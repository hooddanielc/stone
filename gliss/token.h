#pragma once

#include <ostream>
#include <string>
#include <utility>
#include <map>
#include "symbols.h"
#include "pos.h"

namespace gliss {

/* A single token from the source text.  It consists of a kind, describing
   the general variety of token it is, and a text which is copied from the
   source which gave rise to this token. */
class token_t final {

  public:

  /* Tokens come in various kinds. */
  enum kind_t {
    end = symbol_t::end,
    varying = symbol_t::varying,
    attribute = symbol_t::attribute,
    const_ = symbol_t::const_,
    bool_ = symbol_t::bool_,
    float_ = symbol_t::float_,
    double_ = symbol_t::double_,
    int_ = symbol_t::int_,
    uint_ = symbol_t::uint_,
    break_ = symbol_t::break_,
    continue_ = symbol_t::continue_,
    do_ = symbol_t::do_,
    else_ = symbol_t::else_,
    for_ = symbol_t::for_,
    if_ = symbol_t::if_,
    discard = symbol_t::discard,
    return_ = symbol_t::return_,
    switch_ = symbol_t::switch_,
    case_ = symbol_t::case_,
    default_ = symbol_t::default_,
    subroutine = symbol_t::subroutine,
    bvec2 = symbol_t::bvec2,
    bvec3 = symbol_t::bvec3,
    bvec4 = symbol_t::bvec4,
    ivec2 = symbol_t::ivec2,
    ivec3 = symbol_t::ivec3,
    ivec4 = symbol_t::ivec4,
    uvec2 = symbol_t::uvec2,
    uvec3 = symbol_t::uvec3,
    uvec4 = symbol_t::uvec4,
    vec2 = symbol_t::vec2,
    vec3 = symbol_t::vec3,
    vec4 = symbol_t::vec4,
    mat2 = symbol_t::mat2,
    mat3 = symbol_t::mat3,
    mat4 = symbol_t::mat4,
    centroid = symbol_t::centroid,
    in = symbol_t::in,
    out = symbol_t::out,
    inout = symbol_t::inout,
    uniform = symbol_t::uniform,
    patch = symbol_t::patch,
    sample = symbol_t::sample,
    buffer = symbol_t::buffer,
    shared = symbol_t::shared,
    coherent = symbol_t::coherent,
    volatile_ = symbol_t::volatile_,
    restrict_ = symbol_t::restrict_,
    readonly = symbol_t::readonly,
    writeonly = symbol_t::writeonly,
    dvec2 = symbol_t::dvec2,
    dvec3 = symbol_t::dvec3,
    dvec4 = symbol_t::dvec4,
    dmat2 = symbol_t::dmat2,
    dmat3 = symbol_t::dmat3,
    dmat4 = symbol_t::dmat4,
    noperspective = symbol_t::noperspective,
    flat = symbol_t::flat,
    smooth = symbol_t::smooth,
    layout = symbol_t::layout,
    mat2x2 = symbol_t::mat2x2,
    mat2x3 = symbol_t::mat2x3,
    mat2x4 = symbol_t::mat2x4,
    mat3x2 = symbol_t::mat3x2,
    mat3x3 = symbol_t::mat3x3,
    mat3x4 = symbol_t::mat3x4,
    mat4x2 = symbol_t::mat4x2,
    mat4x3 = symbol_t::mat4x3,
    mat4x4 = symbol_t::mat4x4,
    dmat2x2 = symbol_t::dmat2x2,
    dmat2x3 = symbol_t::dmat2x3,
    dmat2x4 = symbol_t::dmat2x4,
    dmat3x2 = symbol_t::dmat3x2,
    dmat3x3 = symbol_t::dmat3x3,
    dmat3x4 = symbol_t::dmat3x4,
    dmat4x2 = symbol_t::dmat4x2,
    dmat4x3 = symbol_t::dmat4x3,
    dmat4x4 = symbol_t::dmat4x4,
    atomic_uint = symbol_t::atomic_uint,
    sampler1d = symbol_t::sampler1d,
    sampler2d = symbol_t::sampler2d,
    sampler3d = symbol_t::sampler3d,
    samplercube = symbol_t::samplercube,
    sampler1dshadow = symbol_t::sampler1dshadow,
    sampler2dshadow = symbol_t::sampler2dshadow,
    samplercubeshadow = symbol_t::samplercubeshadow,
    sampler1darray = symbol_t::sampler1darray,
    sampler2darray = symbol_t::sampler2darray,
    sampler1darrayshadow = symbol_t::sampler1darrayshadow,
    sampler2darrayshadow = symbol_t::sampler2darrayshadow,
    isampler1d = symbol_t::isampler1d,
    isampler2d = symbol_t::isampler2d,
    isampler3d = symbol_t::isampler3d,
    isamplercube = symbol_t::isamplercube,
    isampler1darray = symbol_t::isampler1darray,
    isampler2darray = symbol_t::isampler2darray,
    usampler1d = symbol_t::usampler1d,
    usampler2d = symbol_t::usampler2d,
    usampler3d = symbol_t::usampler3d,
    usamplercube = symbol_t::usamplercube,
    usampler1darray = symbol_t::usampler1darray,
    usampler2darray = symbol_t::usampler2darray,
    sampler2drect = symbol_t::sampler2drect,
    sampler2drectshadow = symbol_t::sampler2drectshadow,
    isampler2drect = symbol_t::isampler2drect,
    usampler2drect = symbol_t::usampler2drect,
    samplerbuffer = symbol_t::samplerbuffer,
    isamplerbuffer = symbol_t::isamplerbuffer,
    usamplerbuffer = symbol_t::usamplerbuffer,
    samplercubearray = symbol_t::samplercubearray,
    samplercubearrayshadow = symbol_t::samplercubearrayshadow,
    isamplercubearray = symbol_t::isamplercubearray,
    usamplercubearray = symbol_t::usamplercubearray,
    sampler2dms = symbol_t::sampler2dms,
    isampler2dms = symbol_t::isampler2dms,
    usampler2dms = symbol_t::usampler2dms,
    sampler2dmsarray = symbol_t::sampler2dmsarray,
    isampler2dmsarray = symbol_t::isampler2dmsarray,
    usampler2dmsarray = symbol_t::usampler2dmsarray,
    image1d = symbol_t::image1d,
    iimage1d = symbol_t::iimage1d,
    uimage1d = symbol_t::uimage1d,
    image2d = symbol_t::image2d,
    iimage2d = symbol_t::iimage2d,
    uimage2d = symbol_t::uimage2d,
    image3d = symbol_t::image3d,
    iimage3d = symbol_t::iimage3d,
    uimage3d = symbol_t::uimage3d,
    image2drect = symbol_t::image2drect,
    iimage2drect = symbol_t::iimage2drect,
    uimage2drect = symbol_t::uimage2drect,
    imagecube = symbol_t::imagecube,
    iimagecube = symbol_t::iimagecube,
    uimagecube = symbol_t::uimagecube,
    imagebuffer = symbol_t::imagebuffer,
    iimagebuffer = symbol_t::iimagebuffer,
    uimagebuffer = symbol_t::uimagebuffer,
    image1darray = symbol_t::image1darray,
    iimage1darray = symbol_t::iimage1darray,
    uimage1darray = symbol_t::uimage1darray,
    image2darray = symbol_t::image2darray,
    iimage2darray = symbol_t::iimage2darray,
    uimage2darray = symbol_t::uimage2darray,
    imagecubearray = symbol_t::imagecubearray,
    iimagecubearray = symbol_t::iimagecubearray,
    uimagecubearray = symbol_t::uimagecubearray,
    image2dms = symbol_t::image2dms,
    iimage2dms = symbol_t::iimage2dms,
    uimage2dms = symbol_t::uimage2dms,
    image2dmsarray = symbol_t::image2dmsarray,
    iimage2dmsarray = symbol_t::iimage2dmsarray,
    uimage2dmsarray = symbol_t::uimage2dmsarray,
    struct_ = symbol_t::struct_,
    void_ = symbol_t::void_,
    while_ = symbol_t::while_,
    identifier = symbol_t::identifier,
    type_name = symbol_t::type_name,
    floatconstant = symbol_t::floatconstant,
    doubleconstant = symbol_t::doubleconstant,
    intconstant = symbol_t::intconstant,
    uintconstant = symbol_t::uintconstant,
    boolconstant = symbol_t::boolconstant,
    field_selection = symbol_t::field_selection,
    left_op = symbol_t::left_op,
    right_op = symbol_t::right_op,
    inc_op = symbol_t::inc_op,
    dec_op = symbol_t::dec_op,
    le_op = symbol_t::le_op,
    ge_op = symbol_t::ge_op,
    eq_op = symbol_t::eq_op,
    ne_op = symbol_t::ne_op,
    and_op = symbol_t::and_op,
    or_op = symbol_t::or_op,
    xor_op = symbol_t::xor_op,
    mul_assign = symbol_t::mul_assign,
    div_assign = symbol_t::div_assign,
    add_assign = symbol_t::add_assign,
    mod_assign = symbol_t::mod_assign,
    left_assign = symbol_t::left_assign,
    right_assign = symbol_t::right_assign,
    and_assign = symbol_t::and_assign,
    xor_assign = symbol_t::xor_assign,
    or_assign = symbol_t::or_assign,
    sub_assign = symbol_t::sub_assign,
    left_paren = symbol_t::left_paren,
    right_paren = symbol_t::right_paren,
    left_bracket = symbol_t::left_bracket,
    right_bracket = symbol_t::right_bracket,
    left_brace = symbol_t::left_brace,
    right_brace = symbol_t::right_brace,
    dot = symbol_t::dot,
    comma = symbol_t::comma,
    colon = symbol_t::colon,
    equal = symbol_t::equal,
    semicolon = symbol_t::semicolon,
    bang = symbol_t::bang,
    dash = symbol_t::dash,
    tilde = symbol_t::tilde,
    plus = symbol_t::plus,
    star = symbol_t::star,
    slash = symbol_t::slash,
    percent = symbol_t::percent,
    left_angle = symbol_t::left_angle,
    right_angle = symbol_t::right_angle,
    vertical_bar = symbol_t::vertical_bar,
    caret = symbol_t::caret,
    ampersand = symbol_t::ampersand,
    question = symbol_t::question,
    invariant = symbol_t::invariant,
    precise = symbol_t::precise,
    high_precision = symbol_t::high_precision,
    medium_precision = symbol_t::medium_precision,
    low_precision = symbol_t::low_precision,
    precision = symbol_t::precision,
    reserved_keyword = symbol_t::reserved_keyword
  };

  /* Cache the position and kind and set the text to the empty string. */
  token_t(const pos_t &pos, kind_t kind): pos(pos), kind(kind) {}

  /* Cache the position and kind and the text. */
  token_t(const pos_t &pos, kind_t kind, std::string &&text):
    pos(pos),
    kind(kind),
    text(std::move(text)) {}

  /* See kind_t, above. */
  kind_t get_kind() const noexcept {
    return kind;
  }

  /* The position in the source at which this token appeared. */
  const pos_t &get_pos() const noexcept {
    return pos;
  }

  /* The text that gave rise to this token, if relevant; otherwise, this is
     the empty string. */
  const std::string &get_text() const noexcept {
    return text;
  }

  /* A human-readable description of a token kind. */
  static const char *get_desc(kind_t kind) {
    const char *desc;
    switch (kind) {
      case end: desc = "END"; break;
      case attribute: desc = "ATTRIBUTE"; break;
      case varying: desc = "VARYING"; break;
      case const_: desc = "CONST"; break;
      case bool_: desc = "BOOL"; break;
      case float_: desc = "FLOAT"; break;
      case double_: desc = "DOUBLE"; break;
      case int_: desc = "INT"; break;
      case uint_: desc = "UINT"; break;
      case break_: desc = "BREAK"; break;
      case continue_: desc = "CONTINUE"; break;
      case do_: desc = "DO"; break;
      case else_: desc = "ELSE"; break;
      case for_: desc = "FOR"; break;
      case if_: desc = "IF"; break;
      case discard: desc = "DISCARD"; break;
      case return_: desc = "RETURN"; break;
      case switch_: desc = "SWITCH"; break;
      case case_: desc = "CASE"; break;
      case default_: desc = "DEFAULT"; break;
      case subroutine: desc = "SUBROUTINE"; break;
      case bvec2: desc = "BVEC2"; break;
      case bvec3: desc = "BVEC3"; break;
      case bvec4: desc = "BVEC4"; break;
      case ivec2: desc = "IVEC2"; break;
      case ivec3: desc = "IVEC3"; break;
      case ivec4: desc = "IVEC4"; break;
      case uvec2: desc = "UVEC2"; break;
      case uvec3: desc = "UVEC3"; break;
      case uvec4: desc = "UVEC4"; break;
      case vec2: desc = "VEC2"; break;
      case vec3: desc = "VEC3"; break;
      case vec4: desc = "VEC4"; break;
      case mat2: desc = "MAT2"; break;
      case mat3: desc = "MAT3"; break;
      case mat4: desc = "MAT4"; break;
      case centroid: desc = "CENTROID"; break;
      case in: desc = "IN"; break;
      case out: desc = "OUT"; break;
      case inout: desc = "INOUT"; break;
      case uniform: desc = "UNIFORM"; break;
      case patch: desc = "PATCH"; break;
      case sample: desc = "SAMPLE"; break;
      case buffer: desc = "BUFFER"; break;
      case shared: desc = "SHARED"; break;
      case coherent: desc = "COHERENT"; break;
      case volatile_: desc = "VOLATILE"; break;
      case restrict_: desc = "RESTRICT"; break;
      case readonly: desc = "READONLY"; break;
      case writeonly: desc = "WRITEONLY"; break;
      case dvec2: desc = "DVEC2"; break;
      case dvec3: desc = "DVEC3"; break;
      case dvec4: desc = "DVEC4"; break;
      case dmat2: desc = "DMAT2"; break;
      case dmat3: desc = "DMAT3"; break;
      case dmat4: desc = "DMAT4"; break;
      case noperspective: desc = "NOPERSPECTIVE"; break;
      case flat: desc = "FLAT"; break;
      case smooth: desc = "SMOOTH"; break;
      case layout: desc = "LAYOUT"; break;
      case mat2x2: desc = "MAT2X2"; break;
      case mat2x3: desc = "MAT2X3"; break;
      case mat2x4: desc = "MAT2X4"; break;
      case mat3x2: desc = "MAT3X2"; break;
      case mat3x3: desc = "MAT3X3"; break;
      case mat3x4: desc = "MAT3X4"; break;
      case mat4x2: desc = "MAT4X2"; break;
      case mat4x3: desc = "MAT4X3"; break;
      case mat4x4: desc = "MAT4X4"; break;
      case dmat2x2: desc = "DMAT2X2"; break;
      case dmat2x3: desc = "DMAT2X3"; break;
      case dmat2x4: desc = "DMAT2X4"; break;
      case dmat3x2: desc = "DMAT3X2"; break;
      case dmat3x3: desc = "DMAT3X3"; break;
      case dmat3x4: desc = "DMAT3X4"; break;
      case dmat4x2: desc = "DMAT4X2"; break;
      case dmat4x3: desc = "DMAT4X3"; break;
      case dmat4x4: desc = "DMAT4X4"; break;
      case atomic_uint: desc = "ATOMIC_UINT"; break;
      case sampler1d: desc = "SAMPLER1D"; break;
      case sampler2d: desc = "SAMPLER2D"; break;
      case sampler3d: desc = "SAMPLER3D"; break;
      case samplercube: desc = "SAMPLERCUBE"; break;
      case sampler1dshadow: desc = "SAMPLER1DSHADOW"; break;
      case sampler2dshadow: desc = "SAMPLER2DSHADOW"; break;
      case samplercubeshadow: desc = "SAMPLERCUBESHADOW"; break;
      case sampler1darray: desc = "SAMPLER1DARRAY"; break;
      case sampler2darray: desc = "SAMPLER2DARRAY"; break;
      case sampler1darrayshadow: desc = "SAMPLER1DARRAYSHADOW"; break;
      case sampler2darrayshadow: desc = "SAMPLER2DARRAYSHADOW"; break;
      case isampler1d: desc = "ISAMPLER1D"; break;
      case isampler2d: desc = "ISAMPLER2D"; break;
      case isampler3d: desc = "ISAMPLER3D"; break;
      case isamplercube: desc = "ISAMPLERCUBE"; break;
      case isampler1darray: desc = "ISAMPLER1DARRAY"; break;
      case isampler2darray: desc = "ISAMPLER2DARRAY"; break;
      case usampler1d: desc = "USAMPLER1D"; break;
      case usampler2d: desc = "USAMPLER2D"; break;
      case usampler3d: desc = "USAMPLER3D"; break;
      case usamplercube: desc = "USAMPLERCUBE"; break;
      case usampler1darray: desc = "USAMPLER1DARRAY"; break;
      case usampler2darray: desc = "USAMPLER2DARRAY"; break;
      case sampler2drect: desc = "SAMPLER2DRECT"; break;
      case sampler2drectshadow: desc = "SAMPLER2DRECTSHADOW"; break;
      case isampler2drect: desc = "ISAMPLER2DRECT"; break;
      case usampler2drect: desc = "USAMPLER2DRECT"; break;
      case samplerbuffer: desc = "SAMPLERBUFFER"; break;
      case isamplerbuffer: desc = "ISAMPLERBUFFER"; break;
      case usamplerbuffer: desc = "USAMPLERBUFFER"; break;
      case samplercubearray: desc = "SAMPLERCUBEARRAY"; break;
      case samplercubearrayshadow: desc = "SAMPLERCUBEARRAYSHADOW"; break;
      case isamplercubearray: desc = "ISAMPLERCUBEARRAY"; break;
      case usamplercubearray: desc = "USAMPLERCUBEARRAY"; break;
      case sampler2dms: desc = "SAMPLER2DMS"; break;
      case isampler2dms: desc = "ISAMPLER2DMS"; break;
      case usampler2dms: desc = "USAMPLER2DMS"; break;
      case sampler2dmsarray: desc = "SAMPLER2DMSARRAY"; break;
      case isampler2dmsarray: desc = "ISAMPLER2DMSARRAY"; break;
      case usampler2dmsarray: desc = "USAMPLER2DMSARRAY"; break;
      case image1d: desc = "IMAGE1D"; break;
      case iimage1d: desc = "IIMAGE1D"; break;
      case uimage1d: desc = "UIMAGE1D"; break;
      case image2d: desc = "IMAGE2D"; break;
      case iimage2d: desc = "IIMAGE2D"; break;
      case uimage2d: desc = "UIMAGE2D"; break;
      case image3d: desc = "IMAGE3D"; break;
      case iimage3d: desc = "IIMAGE3D"; break;
      case uimage3d: desc = "UIMAGE3D"; break;
      case image2drect: desc = "IMAGE2DRECT"; break;
      case iimage2drect: desc = "IIMAGE2DRECT"; break;
      case uimage2drect: desc = "UIMAGE2DRECT"; break;
      case imagecube: desc = "IMAGECUBE"; break;
      case iimagecube: desc = "IIMAGECUBE"; break;
      case uimagecube: desc = "UIMAGECUBE"; break;
      case imagebuffer: desc = "IMAGEBUFFER"; break;
      case iimagebuffer: desc = "IIMAGEBUFFER"; break;
      case uimagebuffer: desc = "UIMAGEBUFFER"; break;
      case image1darray: desc = "IMAGE1DARRAY"; break;
      case iimage1darray: desc = "IIMAGE1DARRAY"; break;
      case uimage1darray: desc = "UIMAGE1DARRAY"; break;
      case image2darray: desc = "IMAGE2DARRAY"; break;
      case iimage2darray: desc = "IIMAGE2DARRAY"; break;
      case uimage2darray: desc = "UIMAGE2DARRAY"; break;
      case imagecubearray: desc = "IMAGECUBEARRAY"; break;
      case iimagecubearray: desc = "IIMAGECUBEARRAY"; break;
      case uimagecubearray: desc = "UIMAGECUBEARRAY"; break;
      case image2dms: desc = "IMAGE2DMS"; break;
      case iimage2dms: desc = "IIMAGE2DMS"; break;
      case uimage2dms: desc = "UIMAGE2DMS"; break;
      case image2dmsarray: desc = "IMAGE2DMSARRAY"; break;
      case iimage2dmsarray: desc = "IIMAGE2DMSARRAY"; break;
      case uimage2dmsarray: desc = "UIMAGE2DMSARRAY"; break;
      case struct_: desc = "STRUCT"; break;
      case void_: desc = "VOID"; break;
      case while_: desc = "WHILE"; break;
      case identifier: desc = "IDENTIFIER"; break;
      case type_name: desc = "TYPE_NAME"; break;
      case floatconstant: desc = "FLOATCONSTANT"; break;
      case doubleconstant: desc = "DOUBLECONSTANT"; break;
      case intconstant: desc = "INTCONSTANT"; break;
      case uintconstant: desc = "UINTCONSTANT"; break;
      case boolconstant: desc = "BOOLCONSTANT"; break;
      case field_selection: desc = "FIELD_SELECTION"; break;
      case left_op: desc = "LEFT_OP"; break;
      case right_op: desc = "RIGHT_OP"; break;
      case inc_op: desc = "INC_OP"; break;
      case dec_op: desc = "DEC_OP"; break;
      case le_op: desc = "LE_OP"; break;
      case ge_op: desc = "GE_OP"; break;
      case eq_op: desc = "EQ_OP"; break;
      case ne_op: desc = "NE_OP"; break;
      case and_op: desc = "AND_OP"; break;
      case or_op: desc = "OR_OP"; break;
      case xor_op: desc = "XOR_OP"; break;
      case mul_assign: desc = "MUL_ASSIGN"; break;
      case div_assign: desc = "DIV_ASSIGN"; break;
      case add_assign: desc = "ADD_ASSIGN"; break;
      case mod_assign: desc = "MOD_ASSIGN"; break;
      case left_assign: desc = "LEFT_ASSIGN"; break;
      case right_assign: desc = "RIGHT_ASSIGN"; break;
      case and_assign: desc = "AND_ASSIGN"; break;
      case xor_assign: desc = "XOR_ASSIGN"; break;
      case or_assign: desc = "OR_ASSIGN"; break;
      case sub_assign: desc = "SUB_ASSIGN"; break;
      case left_paren: desc = "LEFT_PAREN"; break;
      case right_paren: desc = "RIGHT_PAREN"; break;
      case left_bracket: desc = "LEFT_BRACKET"; break;
      case right_bracket: desc = "RIGHT_BRACKET"; break;
      case left_brace: desc = "LEFT_BRACE"; break;
      case right_brace: desc = "RIGHT_BRACE"; break;
      case dot: desc = "DOT"; break;
      case comma: desc = "COMMA"; break;
      case colon: desc = "COLON"; break;
      case equal: desc = "EQUAL"; break;
      case semicolon: desc = "SEMICOLON"; break;
      case bang: desc = "BANG"; break;
      case dash: desc = "DASH"; break;
      case tilde: desc = "TILDE"; break;
      case plus: desc = "PLUS"; break;
      case star: desc = "STAR"; break;
      case slash: desc = "SLASH"; break;
      case percent: desc = "PERCENT"; break;
      case left_angle: desc = "LEFT_ANGLE"; break;
      case right_angle: desc = "RIGHT_ANGLE"; break;
      case vertical_bar: desc = "VERTICAL_BAR"; break;
      case caret: desc = "CARET"; break;
      case ampersand: desc = "AMPERSAND"; break;
      case question: desc = "QUESTION"; break;
      case invariant: desc = "INVARIANT"; break;
      case precise: desc = "PRECISE"; break;
      case high_precision: desc = "HIGH_PRECISION"; break;
      case medium_precision: desc = "MEDIUM_PRECISION"; break;
      case low_precision: desc = "LOW_PRECISION"; break;
      case precision: desc = "PRECISION"; break;
      case reserved_keyword: desc = "RESERVED_KEYWORD"; break;
    }
    return desc;
  }

  /* A human-readable description of a token kind. */
  static kind_t uppercase_to_kind(const std::string &str) {
    static const std::map<std::string, kind_t> keywords = {
      { "END", end },
      { "ATTRIBUTE", attribute },
      { "VARYING", varying },
      { "CONST", const_ },
      { "BOOL", bool_ },
      { "FLOAT", float_ },
      { "DOUBLE", double_ },
      { "INT", int_ },
      { "UINT", uint_ },
      { "BREAK", break_ },
      { "CONTINUE", continue_ },
      { "DO", do_ },
      { "ELSE", else_ },
      { "FOR", for_ },
      { "IF", if_ },
      { "DISCARD", discard },
      { "RETURN", return_ },
      { "SWITCH", switch_ },
      { "CASE", case_ },
      { "DEFAULT", default_ },
      { "SUBROUTINE", subroutine },
      { "BVEC2", bvec2 },
      { "BVEC3", bvec3 },
      { "BVEC4", bvec4 },
      { "IVEC2", ivec2 },
      { "IVEC3", ivec3 },
      { "IVEC4", ivec4 },
      { "UVEC2", uvec2 },
      { "UVEC3", uvec3 },
      { "UVEC4", uvec4 },
      { "VEC2", vec2 },
      { "VEC3", vec3 },
      { "VEC4", vec4 },
      { "MAT2", mat2 },
      { "MAT3", mat3 },
      { "MAT4", mat4 },
      { "CENTROID", centroid },
      { "IN", in },
      { "OUT", out },
      { "INOUT", inout },
      { "UNIFORM", uniform },
      { "PATCH", patch },
      { "SAMPLE", sample },
      { "BUFFER", buffer },
      { "SHARED", shared },
      { "COHERENT", coherent },
      { "VOLATILE", volatile_ },
      { "RESTRICT", restrict_ },
      { "READONLY", readonly },
      { "WRITEONLY", writeonly },
      { "DVEC2", dvec2 },
      { "DVEC3", dvec3 },
      { "DVEC4", dvec4 },
      { "DMAT2", dmat2 },
      { "DMAT3", dmat3 },
      { "DMAT4", dmat4 },
      { "NOPERSPECTIVE", noperspective },
      { "FLAT", flat },
      { "SMOOTH", smooth },
      { "LAYOUT", layout },
      { "MAT2X2", mat2x2 },
      { "MAT2X3", mat2x3 },
      { "MAT2X4", mat2x4 },
      { "MAT3X2", mat3x2 },
      { "MAT3X3", mat3x3 },
      { "MAT3X4", mat3x4 },
      { "MAT4X2", mat4x2 },
      { "MAT4X3", mat4x3 },
      { "MAT4X4", mat4x4 },
      { "DMAT2X2", dmat2x2 },
      { "DMAT2X3", dmat2x3 },
      { "DMAT2X4", dmat2x4 },
      { "DMAT3X2", dmat3x2 },
      { "DMAT3X3", dmat3x3 },
      { "DMAT3X4", dmat3x4 },
      { "DMAT4X2", dmat4x2 },
      { "DMAT4X3", dmat4x3 },
      { "DMAT4X4", dmat4x4 },
      { "ATOMIC_UINT", atomic_uint },
      { "SAMPLER1D", sampler1d },
      { "SAMPLER2D", sampler2d },
      { "SAMPLER3D", sampler3d },
      { "SAMPLERCUBE", samplercube },
      { "SAMPLER1DSHADOW", sampler1dshadow },
      { "SAMPLER2DSHADOW", sampler2dshadow },
      { "SAMPLERCUBESHADOW", samplercubeshadow },
      { "SAMPLER1DARRAY", sampler1darray },
      { "SAMPLER2DARRAY", sampler2darray },
      { "SAMPLER1DARRAYSHADOW", sampler1darrayshadow },
      { "SAMPLER2DARRAYSHADOW", sampler2darrayshadow },
      { "ISAMPLER1D", isampler1d },
      { "ISAMPLER2D", isampler2d },
      { "ISAMPLER3D", isampler3d },
      { "ISAMPLERCUBE", isamplercube },
      { "ISAMPLER1DARRAY", isampler1darray },
      { "ISAMPLER2DARRAY", isampler2darray },
      { "USAMPLER1D", usampler1d },
      { "USAMPLER2D", usampler2d },
      { "USAMPLER3D", usampler3d },
      { "USAMPLERCUBE", usamplercube },
      { "USAMPLER1DARRAY", usampler1darray },
      { "USAMPLER2DARRAY", usampler2darray },
      { "SAMPLER2DRECT", sampler2drect },
      { "SAMPLER2DRECTSHADOW", sampler2drectshadow },
      { "ISAMPLER2DRECT", isampler2drect },
      { "USAMPLER2DRECT", usampler2drect },
      { "SAMPLERBUFFER", samplerbuffer },
      { "ISAMPLERBUFFER", isamplerbuffer },
      { "USAMPLERBUFFER", usamplerbuffer },
      { "SAMPLERCUBEARRAY", samplercubearray },
      { "SAMPLERCUBEARRAYSHADOW", samplercubearrayshadow },
      { "ISAMPLERCUBEARRAY", isamplercubearray },
      { "USAMPLERCUBEARRAY", usamplercubearray },
      { "SAMPLER2DMS", sampler2dms },
      { "ISAMPLER2DMS", isampler2dms },
      { "USAMPLER2DMS", usampler2dms },
      { "SAMPLER2DMSARRAY", sampler2dmsarray },
      { "ISAMPLER2DMSARRAY", isampler2dmsarray },
      { "USAMPLER2DMSARRAY", usampler2dmsarray },
      { "IMAGE1D", image1d },
      { "IIMAGE1D", iimage1d },
      { "UIMAGE1D", uimage1d },
      { "IMAGE2D", image2d },
      { "IIMAGE2D", iimage2d },
      { "UIMAGE2D", uimage2d },
      { "IMAGE3D", image3d },
      { "IIMAGE3D", iimage3d },
      { "UIMAGE3D", uimage3d },
      { "IMAGE2DRECT", image2drect },
      { "IIMAGE2DRECT", iimage2drect },
      { "UIMAGE2DRECT", uimage2drect },
      { "IMAGECUBE", imagecube },
      { "IIMAGECUBE", iimagecube },
      { "UIMAGECUBE", uimagecube },
      { "IMAGEBUFFER", imagebuffer },
      { "IIMAGEBUFFER", iimagebuffer },
      { "UIMAGEBUFFER", uimagebuffer },
      { "IMAGE1DARRAY", image1darray },
      { "IIMAGE1DARRAY", iimage1darray },
      { "UIMAGE1DARRAY", uimage1darray },
      { "IMAGE2DARRAY", image2darray },
      { "IIMAGE2DARRAY", iimage2darray },
      { "UIMAGE2DARRAY", uimage2darray },
      { "IMAGECUBEARRAY", imagecubearray },
      { "IIMAGECUBEARRAY", iimagecubearray },
      { "UIMAGECUBEARRAY", uimagecubearray },
      { "IMAGE2DMS", image2dms },
      { "IIMAGE2DMS", iimage2dms },
      { "UIMAGE2DMS", uimage2dms },
      { "IMAGE2DMSARRAY", image2dmsarray },
      { "IIMAGE2DMSARRAY", iimage2dmsarray },
      { "UIMAGE2DMSARRAY", uimage2dmsarray },
      { "STRUCT", struct_ },
      { "VOID", void_ },
      { "WHILE", while_ },
      { "IDENTIFIER", identifier },
      { "TYPE_NAME", type_name },
      { "FLOATCONSTANT", floatconstant },
      { "DOUBLECONSTANT", doubleconstant },
      { "INTCONSTANT", intconstant },
      { "UINTCONSTANT", uintconstant },
      { "BOOLCONSTANT", boolconstant },
      { "FIELD_SELECTION", field_selection },
      { "LEFT_OP", left_op },
      { "RIGHT_OP", right_op },
      { "INC_OP", inc_op },
      { "DEC_OP", dec_op },
      { "LE_OP", le_op },
      { "GE_OP", ge_op },
      { "EQ_OP", eq_op },
      { "NE_OP", ne_op },
      { "AND_OP", and_op },
      { "OR_OP", or_op },
      { "XOR_OP", xor_op },
      { "MUL_ASSIGN", mul_assign },
      { "DIV_ASSIGN", div_assign },
      { "ADD_ASSIGN", add_assign },
      { "MOD_ASSIGN", mod_assign },
      { "LEFT_ASSIGN", left_assign },
      { "RIGHT_ASSIGN", right_assign },
      { "AND_ASSIGN", and_assign },
      { "XOR_ASSIGN", xor_assign },
      { "OR_ASSIGN", or_assign },
      { "SUB_ASSIGN", sub_assign },
      { "LEFT_PAREN", left_paren },
      { "RIGHT_PAREN", right_paren },
      { "LEFT_BRACKET", left_bracket },
      { "RIGHT_BRACKET", right_bracket },
      { "LEFT_BRACE", left_brace },
      { "RIGHT_BRACE", right_brace },
      { "DOT", dot },
      { "COMMA", comma },
      { "COLON", colon },
      { "EQUAL", equal },
      { "SEMICOLON", semicolon },
      { "BANG", bang },
      { "DASH", dash },
      { "TILDE", tilde },
      { "PLUS", plus },
      { "STAR", star },
      { "SLASH", slash },
      { "PERCENT", percent },
      { "LEFT_ANGLE", left_angle },
      { "RIGHT_ANGLE", right_angle },
      { "VERTICAL_BAR", vertical_bar },
      { "CARET", caret },
      { "AMPERSAND", ampersand },
      { "QUESTION", question },
      { "INVARIANT", invariant },
      { "PRECISE", precise },
      { "HIGH_PRECISION", high_precision },
      { "MEDIUM_PRECISION", medium_precision },
      { "LOW_PRECISION", low_precision },
      { "PRECISION", precision },
      { "RESERVED_KEYWORD", reserved_keyword }
    };

    auto iter = keywords.find(str);
    if (iter != keywords.end()) {
      return iter->second;
    }

    return token_t::identifier;
  }

  static kind_t str_to_kind(const std::string &str) {
    static const std::map<std::string, kind_t> keywords = {
      { "attribute", token_t::attribute },
      { "const", token_t::const_ },
      { "uniform", token_t::uniform },
      { "varying", token_t::varying },
      { "buffer", token_t::buffer },
      { "shared", token_t::shared },
      { "coherent", token_t::coherent },
      { "volatile", token_t::volatile_ },
      { "restrict", token_t::restrict_ },
      { "readonly", token_t::readonly },
      { "writeonly", token_t::writeonly },
      { "atomic_uint", token_t::atomic_uint },
      { "layout", token_t::layout },
      { "centroid", token_t::centroid },
      { "flat", token_t::flat },
      { "smooth", token_t::smooth },
      { "noperspective", token_t::noperspective },
      { "patch", token_t::patch },
      { "sample", token_t::sample },
      { "break", token_t::break_ },
      { "continue", token_t::continue_ },
      { "do", token_t::do_ },
      { "for", token_t::for_ },
      { "while", token_t::while_ },
      { "switch", token_t::switch_ },
      { "case", token_t::case_ },
      { "default", token_t::default_ },
      { "if", token_t::if_ },
      { "else", token_t::else_ },
      { "subroutine", token_t::subroutine },
      { "in", token_t::in },
      { "out", token_t::out },
      { "inout", token_t::inout },
      { "float", token_t::float_ },
      { "double", token_t::double_ },
      { "int", token_t::int_ },
      { "void", token_t::void_ },
      { "bool", token_t::bool_ },
      { "true", token_t::boolconstant },
      { "false", token_t::boolconstant },
      { "invariant", token_t::invariant },
      { "precise", token_t::precise },
      { "discard", token_t::discard },
      { "return", token_t::return_ },
      { "mat2", token_t::mat2 },
      { "mat3", token_t::mat3 },
      { "mat4", token_t::mat4 },
      { "dmat2", token_t::dmat2 },
      { "dmat3", token_t::dmat3 },
      { "dmat4", token_t::dmat4 },
      { "mat2x2", token_t::mat2x2 },
      { "mat2x3", token_t::mat2x3 },
      { "mat2x4", token_t::mat2x4 },
      { "dmat2x2", token_t::dmat2x2 },
      { "dmat2x3", token_t::dmat2x3 },
      { "dmat2x4", token_t::dmat2x4 },
      { "mat3x2", token_t::mat3x2 },
      { "mat3x3", token_t::mat3x3 },
      { "mat3x4", token_t::mat3x4 },
      { "dmat3x2", token_t::dmat3x2 },
      { "dmat3x3", token_t::dmat3x3 },
      { "dmat3x4", token_t::dmat3x4 },
      { "mat4x2", token_t::mat4x2 },
      { "mat4x3", token_t::mat4x3 },
      { "mat4x4", token_t::mat4x4 },
      { "dmat4x2", token_t::dmat4x2 },
      { "dmat4x3", token_t::dmat4x3 },
      { "dmat4x4", token_t::dmat4x4 },
      { "vec2", token_t::vec2 },
      { "vec3", token_t::vec3 },
      { "vec4", token_t::vec4 },
      { "ivec2", token_t::ivec2 },
      { "ivec3", token_t::ivec3 },
      { "ivec4", token_t::ivec4 },
      { "bvec2", token_t::bvec2 },
      { "bvec3", token_t::bvec3 },
      { "bvec4", token_t::bvec4 },
      { "dvec2", token_t::dvec2 },
      { "dvec3", token_t::dvec3 },
      { "dvec4", token_t::dvec4 },
      { "uint", token_t::uint_ },
      { "uvec2", token_t::uvec2 },
      { "uvec3", token_t::uvec3 },
      { "uvec4", token_t::uvec4 },
      { "lowp", token_t::low_precision },
      { "mediump", token_t::medium_precision },
      { "highp", token_t::high_precision },
      { "precision", token_t::precision },
      { "sampler1D", token_t::sampler1d },
      { "sampler2D", token_t::sampler2d },
      { "sampler3D", token_t::sampler3d },
      { "samplerCube", token_t::samplercube },
      { "sampler1DShadow", token_t::sampler1dshadow },
      { "sampler2DShadow", token_t::sampler2dshadow },
      { "samplerCubeShadow", token_t::samplercubeshadow },
      { "sampler1DArray", token_t::sampler1darray },
      { "sampler2DArray", token_t::sampler2darray },
      { "sampler1DArrayShadow", token_t::sampler1darrayshadow },
      { "sampler2DArrayShadow", token_t::sampler2darrayshadow },
      { "isampler1D", token_t::isampler1d },
      { "isampler2D", token_t::isampler2d },
      { "isampler3D", token_t::isampler3d },
      { "isamplerCube", token_t::isamplercube },
      { "isampler1DArray", token_t::isampler1darray },
      { "isampler2DArray", token_t::isampler2darray },
      { "usampler1D", token_t::usampler1d },
      { "usampler2D", token_t::usampler2d },
      { "usampler3D", token_t::usampler3d },
      { "usamplerCube", token_t::usamplercube },
      { "usampler1DArray", token_t::usampler1darray },
      { "usampler2DArray", token_t::usampler2darray },
      { "sampler2DRect", token_t::sampler2drect },
      { "sampler2DRectShadow", token_t::sampler2drectshadow },
      { "isampler2DRect", token_t::isampler2drect },
      { "usampler2DRect", token_t::usampler2drect },
      { "samplerBuffer", token_t::samplerbuffer },
      { "isamplerBuffer", token_t::isamplerbuffer },
      { "usamplerBuffer", token_t::usamplerbuffer },
      { "sampler2DMS", token_t::sampler2dms },
      { "isampler2DMS", token_t::isampler2dms },
      { "usampler2DMS", token_t::usampler2dms },
      { "sampler2DMSArray", token_t::sampler2dmsarray },
      { "isampler2DMSArray", token_t::isampler2dmsarray },
      { "usampler2DMSArray", token_t::usampler2dmsarray },
      { "samplerCubeArray", token_t::samplercubearray },
      { "samplerCubeArrayShadow", token_t::samplercubearrayshadow },
      { "isamplerCubeArray", token_t::isamplercubearray },
      { "usamplerCubeArray", token_t::usamplercubearray },
      { "image1D", token_t::image1d },
      { "iimage1D", token_t::iimage1d },
      { "uimage1D", token_t::uimage1d },
      { "image2D", token_t::image2d },
      { "iimage2D", token_t::iimage2d },
      { "uimage2D", token_t::uimage2d },
      { "image3D", token_t::image3d },
      { "iimage3D", token_t::iimage3d },
      { "uimage3D", token_t::uimage3d },
      { "image2DRect", token_t::image2drect },
      { "iimage2DRect", token_t::iimage2drect },
      { "uimage2DRect", token_t::uimage2drect },
      { "imageCube", token_t::imagecube },
      { "iimageCube", token_t::iimagecube },
      { "uimageCube", token_t::uimagecube },
      { "imageBuffer", token_t::imagebuffer },
      { "iimageBuffer", token_t::iimagebuffer },
      { "uimageBuffer", token_t::uimagebuffer },
      { "image1DArray", token_t::image1darray },
      { "iimage1DArray", token_t::iimage1darray },
      { "uimage1DArray", token_t::uimage1darray },
      { "image2DArray", token_t::image2darray },
      { "iimage2DArray", token_t::iimage2darray },
      { "uimage2DArray", token_t::uimage2darray },
      { "imageCubeArray", token_t::imagecubearray },
      { "iimageCubeArray", token_t::iimagecubearray },
      { "uimageCubeArray", token_t::uimagecubearray },
      { "image2DMS", token_t::image2dms },
      { "iimage2DMS", token_t::iimage2dms },
      { "uimage2DMS", token_t::uimage2dms },
      { "image2DMSArray", token_t::image2dmsarray },
      { "iimage2DMSArray", token_t::iimage2dmsarray },
      { "uimage2DMSArray", token_t::uimage2dmsarray },
      { "struct", token_t::struct_ },
      { "common", token_t::reserved_keyword },
      { "partition", token_t::reserved_keyword },
      { "active", token_t::reserved_keyword },
      { "asm", token_t::reserved_keyword },
      { "class", token_t::reserved_keyword },
      { "union", token_t::reserved_keyword },
      { "enum", token_t::reserved_keyword },
      { "typedef", token_t::reserved_keyword },
      { "template", token_t::reserved_keyword },
      { "this", token_t::reserved_keyword },
      { "resource", token_t::reserved_keyword },
      { "goto", token_t::reserved_keyword },
      { "inline", token_t::reserved_keyword },
      { "noinline", token_t::reserved_keyword },
      { "public", token_t::reserved_keyword },
      { "static", token_t::reserved_keyword },
      { "extern", token_t::reserved_keyword },
      { "external", token_t::reserved_keyword },
      { "interface", token_t::reserved_keyword },
      { "long", token_t::reserved_keyword },
      { "short", token_t::reserved_keyword },
      { "half", token_t::reserved_keyword },
      { "fixed", token_t::reserved_keyword },
      { "unsigned", token_t::reserved_keyword },
      { "superp", token_t::reserved_keyword },
      { "input", token_t::reserved_keyword },
      { "output", token_t::reserved_keyword },
      { "hvec2", token_t::reserved_keyword },
      { "hvec3", token_t::reserved_keyword },
      { "hvec4", token_t::reserved_keyword },
      { "fvec2", token_t::reserved_keyword },
      { "fvec3", token_t::reserved_keyword },
      { "fvec4", token_t::reserved_keyword },
      { "sampler3DRect", token_t::reserved_keyword },
      { "filter", token_t::reserved_keyword },
      { "sizeof", token_t::reserved_keyword },
      { "cast", token_t::reserved_keyword },
      { "namespace", token_t::reserved_keyword },
      { "using", token_t::reserved_keyword }
    };

    auto iter = keywords.find(str);
    if (iter != keywords.end()) {
      return iter->second;
    }

    return token_t::identifier;
  }

  /* Writes a human-readable dump of the token.  This is for debugging
     purposes only.  In production, a user never sees tokens directly. */
  friend std::ostream &operator<<(std::ostream &strm, const token_t &that) {
    strm << that.pos << "; " << get_desc(that.kind);
    if (!that.text.empty()) {
      strm << "; \"" << that.text << '"';
    }
    return strm;
  }

private:

  /* See accessors. */
  pos_t pos;

  /* See accessor. */
  kind_t kind;

  /* See accessor. */
  std::string text;

};  // token_t

}   // gliss
