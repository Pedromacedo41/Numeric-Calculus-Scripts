function pvi2ordem

  f= @(x,y,z) -y;
  y(1)=0;
  z(1)=1;
  x=0;
  h= 0.1;
  n=2;

  for i = 1:n
  
    r1=f(x,y(i),z(i));
    r2=f(x+h,y(i)+z(i)*h,z(i)+h*r1);
    
    y(i+1)=y(i)+(h/2)*(2*z(i)+h*r1);
    z(i+1)=z(i)+(h/2)*(r1+r2);
    x=x+h;
  
  endfor
  
  display(y(i+1));

endfunction

