function y = edoquarta

  f= @(x,y) y+x;
  y(1)=1;
  x= -1;
  h= 0.1;
  n=9;

  for i = 1:n
    r1=f(x,y(i));
    r2=f(x+h/2,y(i)+r1*h/2);
    r3=f(x+h/2,y(i)+r2*h/2);
    r4=f(x+h,y(i)+r3*h);
    r= (r1+2*r2+2*r3+r4)/6;
  
    y(i+1)=y(i)+r*h;
    x=x+h;
  endfor
  
  f= @(x,y) y-x;
  y(n+2)=e-1;
  x= 0;
  h= 0.1;

  for i = (n+2):(2*n+2)
    r1=f(x,y(i));
    r2=f(x+h/2,y(i)+r1*h/2);
    r3=f(x+h/2,y(i)+r2*h/2);
    r4=f(x+h,y(i)+r3*h);
    r= (r1+2*r2+2*r3+r4)/6;
  
    y(i+1)=y(i)+r*h;
    x=x+h;
  endfor

 
endfunction