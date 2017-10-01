// http://glslsandbox.com/e#42777.0
#ifdef GL_ES
precision mediump float;
#endif

#extension GL_OES_standard_derivatives : enable

uniform float time;
uniform vec2 mouse;
uniform vec2 resolution;

const vec2 t = vec2(.5, -0.809);

void main( void ) 
{
  vec2 p = ( gl_FragCoord.xy / resolution.xy ) * 8. - 4.;
  p.x *= resolution.x/resolution.y;
  
  float x1 = p.x;
  float x2 = p.x * t.x + p.y * t.y;
  float x3 = p.x * t.x + p.y *-t.y;
  
  float hit = 1.0;
  hit += step(fract(x1), .5);
  hit += step(fract(x2), .5);
  hit += step(fract(x3), .5);
  hit = step(fract(hit*0.35), .5);
  
  gl_FragColor = vec4(hit);

}
