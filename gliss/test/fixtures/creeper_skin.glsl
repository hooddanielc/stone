// http://glslsandbox.com/e#42779.0
#ifdef GL_ES
precision mediump float;
#endif

#extension GL_OES_standard_derivatives : enable

uniform float time;
uniform vec2 mouse;
uniform vec2 resolution;

// Making a XOR-texture using only floats

void main( void ) {

  vec2 pos = gl_FragCoord.xy/resolution.y;

  float size = 1024.0 * (1.0 + 0.5*sin(time));
  float x = floor(pos.x*size);
  float y = floor(pos.y*size);

  // Bits
  bool xb[8], yb[8];
  for (int i = 0; i < 8; i++) {
    xb[i] = floor(x*0.5) == x*0.5;
    yb[i] = floor(y*0.5) == y*0.5;
    x = floor(x*0.5);
    y = floor(y*0.5);
  }

  // Bitwise AND
  float bit_and = 0.0;
  if (xb[0] && yb[0]) bit_and += 1.0;
  if (xb[1] && yb[1]) bit_and += 2.0;
  if (xb[2] && yb[2]) bit_and += 4.0;
  if (xb[3] && yb[3]) bit_and += 8.0;
  if (xb[4] && yb[4]) bit_and += 16.0;
  if (xb[5] && yb[5]) bit_and += 32.0;
  if (xb[6] && yb[6]) bit_and += 64.0;
  if (xb[7] && yb[7]) bit_and += 128.0;
  bit_and = bit_and / 255.0;

  // Bitwise OR
  float bit_or = 0.0;
  if (xb[0] || yb[0]) bit_or += 1.0;
  if (xb[1] || yb[1]) bit_or += 2.0;
  if (xb[2] || yb[2]) bit_or += 4.0;
  if (xb[3] || yb[3]) bit_or += 8.0;
  if (xb[4] || yb[4]) bit_or += 16.0;
  if (xb[5] || yb[5]) bit_or += 32.0;
  if (xb[6] || yb[6]) bit_or += 64.0;
  if (xb[7] || yb[7]) bit_or += 128.0;
  bit_or = bit_or / 255.0;

  // Bitwise XOR
  float bit_xor = 0.0;
  if (xb[0] != yb[0]) bit_xor += 1.0;
  if (xb[1] != yb[1]) bit_xor += 2.0;
  if (xb[2] != yb[2]) bit_xor += 4.0;
  if (xb[3] != yb[3]) bit_xor += 8.0;
  if (xb[4] != yb[4]) bit_xor += 16.0;
  if (xb[5] != yb[5]) bit_xor += 32.0;
  if (xb[6] != yb[6]) bit_xor += 64.0;
  if (xb[7] != yb[7]) bit_xor += 128.0;
  bit_xor = bit_xor / 255.0;
  
  vec3 color = vec3(bit_xor*mouse.x, bit_or*mouse.y, bit_and*mouse.x*mouse.y);
  
  gl_FragColor = vec4(color, 1.0);
}
