function integraldupladesimpson

    n=1000;
    limitedeforaa=0.1;
    limitedeforab=0.5;
    
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
  n=1000;
  
  d= @(x) x*x;
  c= @(x) x*x*x;
  a=c(k);
  b=(d(k));
  
  f= @(y) exp(y/k);  %integrando
 
  h=(b-a)/(2*n);
  int= f(a)+f(b);
  int1=0;
  int2=0;
  if (n>=2)
    for i=1:(n-1)
    
      y1=a+(2*i)*h;
      y2=a+(2*i-1)*h;
      
      int1+=2*f(y1);
      int2+=4*f(y2);
    endfor
  endif
  dd=a+(2*n-1)*h;
  int2+=4.*(f(dd));
  
  int+=(int1+int2);
  int*=h/3;

endfunction