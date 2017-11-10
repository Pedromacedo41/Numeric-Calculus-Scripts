function Trapeziorepetida

  pkg load symbolic;
  format long;
  n=50;
  a=1;
  b=2;
  h=(b-a)/n;
  syms x;
  f=3*x-3;
  int=vpa(subs(f,{x},a))+vpa(subs(f,{x},b));
   
 
  for i=2:(n-1)
   int+=vpa(2*subs(f,{x},(a+(i-1)*h)));
  endfor
 
  int*=h/2;
 
  display(int);

endfunction