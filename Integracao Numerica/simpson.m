function simpson

  pkg load symbolic;
  n=40;
  a=1;
  b=0;
  h=(b-a)/(2*n);
  syms x;
  f=6-6*x^5;
  int=double(subs(f,{x},a))+double(subs(f,{x},b));
  int1=0;
  int2=0;
  
  for i=1:(n-1)
   x1=a+(2*i)*h;
   x2=a+(2*i-1)*h;
   int1+=double(2*subs(f,{x},vpa(x1)));
   int2+=4*double(subs(f,{x},vpa(x2)));
  endfor
  d=a+(2*n-1)*h;
  int2+=4*double(subs(f,{x},d));
  
  int+=(int1+int2);
  int*=h/3;
 
  display(int);

endfunction