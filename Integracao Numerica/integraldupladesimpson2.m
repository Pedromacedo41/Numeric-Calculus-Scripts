function integraldupladesimpson

    n=2;
    limitedeforaa=pi/4;
    limitedeforab=0;
    
    h=(limitedeforab-limitedeforaa)/(2*n);
    
    
    int=simpson2(limitedeforaa)+simpson2(limitedeforab);
    int1=0;
    int2=0;
  
    if (n>=2)
      for i=1:(n-1)
    
        x1=limitedeforaa+(2*i)*h;
        x2=limitedeforaa+(2*i-1)*h;
        int1+=2*simpson2(x1);
        int2+=4*simpson2(x2);
      endfor
    endif
  
    dd=limitedeforaa+(2*n-1)*h;
    int2+=4*simpson2(dd);
  
    int+=(int1+int2);
    int*=h/3;
    display(vpa(int));

endfunction


function int = simpson2(k)  % valor de x;
  n=2;
  pkg load symbolic;
  syms y x;
  d=cos(x);
  c=sin(x);
  a=vpa(subs(c,{x},k));
  b=vpa(subs(d,{x},k));
  
  f= 2*y*sin(k)+(cos(k))^2;  %integrando
 
  h=(b-a)/(2*n);
  int= vpa(subs(f,{y},a))+vpa(subs(f,{y},b));
  int1=0;
  int2=0;
  if (n>=2)
    for i=1:(n-1)
    
      y1=a+(2*i)*h;
      y2=a+(2*i-1)*h;
      
      int1+=2*vpa(subs(f,{y},y1));
      int2+=4*vpa(subs(f,{y},y2));
    endfor
  endif
  dd=a+(2*n-1)*h;
  int2+=4.*vpa(subs(f,{y},dd));
  
  int+=(int1+int2);
  int*=h/3;

endfunction