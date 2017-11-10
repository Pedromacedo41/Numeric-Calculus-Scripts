function integraldupladesimpson

    n=2;
    limitedeforaa=0;
    limitedeforab=2;
    pkg load symbolic;
    syms x;
    c=2*x+2;
    d=x;
    
    h=(limitedeforab-limitedeforaa)/(2*n);
    
    c1=subs(c,{x},limitedeforaa);
    d1=subs(d,{x},limitedeforaa);
    
    c2=subs(c,{x},limitedeforab);
    d2=subs(d,{x},limitedeforab);
   
    int=simpson2(c1,d1,limitedeforaa)+simpson2(c2,d2,limitedeforab);
    int1=0;
    int2=0;
  
    if (n>=2)
      for i=1:(n-1)
    
        x1=limitedeforaa+(2*i)*h;
        x2=limitedeforaa+(2*i-1)*h;
        cx1=subs(c,{x},x1);
        dx1=subs(d,{x},x1);
        cx2=subs(c,{x},x2);
        dx2=subs(d,{x},x2);
        int1+=2*simpson2(cx1,dx1,x1);
        int2+=4*simpson2(cx2,dx2,x2);
      endfor
    endif
  
    dd=limitedeforaa+(2*n-1)*h;
    cx=subs(c,{x},dd);
    dx=subs(d,{x},dd);
    int2+=4*simpson2(cx,dx,dd);
  
    int+=(int1+int2);
    int*=h/3;
    display(vpa(int));

endfunction


function int = simpson2(a,b,k)  %funcaof e valor de x;

  n=2;
  pkg load symbolic;
  syms y;
  
  f= 2*k+y;
 
  h=(b-a)/(2*n);
  int= subs(f,{y},a)+subs(f,{y},b);
  int1=0;
  int2=0;
  
  if (n>=2)
    for i=1:(n-1)
    
      y1=a+(2*i)*h;
      y2=a+(2*i-1)*h;
      
      int1+=2*subs(f,{y},y1);
      int2+=4*subs(f,{y},y2);
    endfor
  endif
  
  dd=a+(2*n-1)*h;
  int2+=4*subs(f,{y},dd);
  
  int+=(int1+int2);
  int*=h/3;
  display(int);

endfunction