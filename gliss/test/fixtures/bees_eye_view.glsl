// http://glslsandbox.com/e#42775.0
#ifdef GL_ES
precision mediump float;
#endif

// Dancing Flower 2017-11-30 by @hintz

uniform float time;
uniform vec2 mouse;
uniform vec2 resolution;

void main(void)
{ 
  float n = 2.5;
  vec2 p = 2.0*(gl_FragCoord.xy-0.5*resolution)/resolution.y;
  p = vec2(7.0*atan(p.y,p.x),0.4*cos((9.0+6.0*sin(time)+2.0*sin(0.88*time))*length(p)));
  vec2 p2 = vec2(n*cos(p.x+0.1*time),p.y); 
  float y0 = p.y + 0.31*sin(p.x+time+10.5*cos(time));
  float y1 = p.y + 0.3*cos(p.x+time+12.5*sin(time));
  y0 *= y0;
  y1 *= y1;
  y0 = sqrt(1.0 - y0 * 60.0 * (sin(8.0*p.x+1.4*time) + 1.4));
  y1 = sqrt(1.0 - y1 * 60.0 * (sin(6.0*p.x-1.5*time) + 1.5));
  float y2 =  cos(p.x+time-1.0+0.5*cos(time));
  float y3 = -sin(p.x+time+1.0+0.5*sin(time));
  float y = max(y0+y2,y1+y3);
  float c = y;
  vec3 color = 0.001*pow(c*c*0.4,10.0)+c*normalize(vec3(c,c+p2.x,-c+p2.x));
  gl_FragColor = vec4(color.yxz,1.0);
}
