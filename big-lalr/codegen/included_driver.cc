
class parser_t {

public:

  using output_stack_t = std::vector<std::shared_ptr<ast_t>>;

  using input_queue_t = std::vector<std::shared_ptr<token_t>>;

  void write_states(std::ostream &strm) {
    strm << "states: ";

    for (auto it = states.begin(); it != states.end(); ++it) {
      strm << (*it);
      if (std::next(it) != states.end()) {
        strm << ", ";
      }
    }
  }

  void write_output(std::ostream &strm) {
    strm << "ast: ";

    for (auto it = output.begin(); it != output.end(); ++it) {
      strm << (*it)->get_name();
      if (std::next(it) != output.end()) {
        strm << ", ";
      }
    }
  }

  void write_input(std::ostream &strm) {
    strm << "input: ";

    for (auto it = input.begin(); it != input.end(); ++it) {
      strm << (*it)->get_name();
      if (std::next(it) != input.end()) {
        strm << ", ";
      }
    }
  }

  using cb_action_t = std::function<void(const action_t &data)>;

  std::vector<cb_action_t> on_step_cbs;
  std::vector<cb_action_t> on_reduce_cbs;
  std::vector<cb_action_t> on_shift_cbs;
  std::vector<cb_action_t> on_accept_cbs;
  std::vector<cb_action_t> on_transition_cbs;

  void on_step(const cb_action_t &cb) {
    on_step_cbs.push_back(cb);
  }

  void on_reduce(const cb_action_t &cb) {
    on_reduce_cbs.push_back(cb);
  }

  void on_accept(const cb_action_t &cb) {
    on_accept_cbs.push_back(cb);
  }

  void on_shift(const cb_action_t &cb) {
    on_shift_cbs.push_back(cb);
  }

  void on_transition(const cb_action_t &cb) {
    on_transition_cbs.push_back(cb);
  }

  void emit_on_step(const action_t &data) {
    for (const auto &cb: on_step_cbs) {
      cb(data);
    }
  }

  void emit_on_reduce(const action_t &data) {
    for (const auto &cb: on_reduce_cbs) {
      cb(data);
    }
  }

  void emit_on_shift(const action_t &data) {
    for (const auto &cb: on_shift_cbs) {
      cb(data);
    }
  }

  void emit_on_accept(const action_t &data) {
    for (const auto &cb: on_accept_cbs) {
      cb(data);
    }
  }

  void emit_on_transition(const action_t &data) {
    for (const auto &cb: on_transition_cbs) {
      cb(data);
    }
  }

  std::vector<std::shared_ptr<token_t>> get_remaining_input() const {
    return input;
  }

  std::vector<std::shared_ptr<ast_t>> get_output() const {
    return output;
  }

  std::vector<std::shared_ptr<ast_t>> parse(input_queue_t tokens) {
    input = tokens;
    go = true;

    while(go) {
      auto action = action_stack.back();
      emit_on_step(action);
      switch (action.first) {
        case restart:
          // accept
          on_restart_action();
          break;
        case reduce:
          // get the rule associated with this action,
          // identify size of rule, pop n tokens
          // from output stack, create reduction, push
          // output. Push transition state on to state stack
          emit_on_reduce(action);
          on_reduce_action();
          break;
        case shift:
          // shift the token and goto next state
          emit_on_shift(action);
          on_shift_action();
          break;
        case transition:
          // push the state identified in goto table
          emit_on_transition(action);
          on_transition_action();
          break;
      }
    }

    return output;
  }

  static std::shared_ptr<parser_t> make() {
    auto ptr = new parser_t();
    std::shared_ptr<parser_t> result(ptr);
    return result;
  }

protected:

  virtual std::shared_ptr<ast_t> reduce_by_id(int id, std::vector<std::shared_ptr<ast_t>> &children) {
    return default_reduce_by_id(id, children);
  }

  std::vector<std::shared_ptr<ast_t>> pop_reduction(int id) {
    int len = rule_lengths[id - 1];
    assert(int(output.size()) >= len);
    std::vector<std::shared_ptr<ast_t>> children;
    for (int i = 0; i < len; ++i) {
      states.pop_back();
      children.push_back(output.back());
      output.pop_back();
    }
    std::reverse(children.begin(), children.end());
    return children;
  }

  void on_restart_action() {
    if (input.size() == 0) {
      go = false;
      emit_on_accept(action_stack.back());
    }
  }

  void on_reduce_action() {
    // lookup the reduction by rule id
    assert(action_stack.back().first == reduce);
    assert(action_stack.back().second >= 0);
    int rule_id = action_stack.back().second;
    std::vector<std::shared_ptr<ast_t>> children = pop_reduction(rule_id);
    auto reduction = reduce_by_id(rule_id, children);
    output.push_back(reduction);

    int last_state = states.back();
    action_stack.push_back(get_transition(reduction->get_symbol_id(), last_state));
  }

  void on_shift_action() {
    assert(action_stack.back().first == shift);
    assert(action_stack.back().second >= 0);

    if (input.empty()) {
      throw throw_unexpected_eof();
      throw std::runtime_error("unexpected end of program");
    }

    auto shifted_token = ast_token_t::make(input.front());
    input.erase(input.begin());
    output.push_back(shifted_token);
    int next_state = action_stack.back().second;

    if (input.empty()) {
      int token_id = static_cast<int>(symbol_t::__break__);
      action_stack.push_back(get_action(token_id, next_state));
    } else {
      int token_id = static_cast<int>(input.front()->get_kind());
      action_stack.push_back(get_action(token_id, next_state));
    }

    states.push_back(next_state);
  }

  void on_transition_action() {
    assert(action_stack.back().first == transition);
    assert(action_stack.back().second >= 0 && action_stack.back().second < INT16_MAX);
    int transition_to = action_stack.back().second;
    states.push_back(transition_to);

    if (input.empty()) {
      int token_id = static_cast<int>(symbol_t::__break__);
      action_stack.push_back(get_action(token_id, transition_to));
    } else {
      int token_id = static_cast<int>(input.front()->get_kind());
      action_stack.push_back(get_action(token_id, transition_to));
    }
  }

  /* get transition from table */
  action_t get_transition(int reduction_id, int state_id) {
    assert(((state_id * num_symbols) + reduction_id) < int(sizeof(actions)));
    auto action = actions[(state_id * num_symbols) + reduction_id];

    if (action < INT16_MAX) {
      return {action_kind_t::transition, action - 1};
    }

    throw_unexpected_token();
    throw std::runtime_error("unexpected token");
  }

  /* get action from table */
  action_t get_action(int token_id, int state_id) {
    assert(((state_id * num_symbols) + token_id) < int(sizeof(actions)));
    auto action = actions[(state_id * num_symbols) + token_id];

    if (action < 0) {
      // reduce
      return {action_kind_t::reduce, action * -1};
    } else if (action == 0) {
      // accept
      return {action_kind_t::restart, 0};
    } else if (action < INT16_MAX) {
      // shift
      return {action_kind_t::shift, action - 1};
    }

    throw_unexpected_token();
    throw std::runtime_error("unexpected token");
  }

  virtual void throw_unexpected_token() const {}

  virtual void throw_unexpected_eof() const {}

  /* temporary input queue */
  input_queue_t input;

  /* state stack */
  std::vector<int> states;

  /* action stack */
  std::vector<action_t> action_stack;

  /* output stack */
  output_stack_t output;

  bool go;

  parser_t(): action_stack({ {action_kind_t::transition, 0} }), go(false) {}

};  // parser_t
