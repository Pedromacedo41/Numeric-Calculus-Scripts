function integraltriplagg  %integralemx

    n=2;
    limitedeforaa=2;
    limitedeforab=-2;
    
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
    display(int);

endfunction

function int = simpson2(k)  %integral em y, k e o parametro x

  n=3;

  c= @(x) 2;
  d= @(x) -2;
  
  a=(c(k)); 
  b=d(k);  
  
  h=(b-a)/(2*n);
  int= simpson3(k,b)+simpson3(k,a);
  int1=0;
  int2=0;
  
  if (n>=2)
    for i=1:(n-1)
    
      y1=a+(2*i)*h;
      y2=a+(2*i-1)*h;
      
      int1+=2*simpson3(k,y1);
      int2+=4*simpson3(k,y2);
    endfor
  endif
  dd=a+(2*n-1)*h;
  int2+=4.*simpson3(k,dd);
  int+=(int1+int2);
  int*=h/3;

endfunction



function int = simpson3(k,t)  % valor de x, de y; integral em z
  n=3;
  
  d= @(x,y) 2;
  c= @(x,y) -2.;
  a=c(k,t); 
  b=d(k,t); 
  
  f= @(z) (x);  %integrando
 
  h=(b-a)/(2*n);
  int= f(a)+f(b);
  int1=0;
  int2=0;
  if (n>=2)
    for i=1:(n-1)
    
      z1=a+(2*i)*h;
      z2=a+(2*i-1)*h;
      
      int1+=2*f(z1);
      int2+=4*f(z2);
    endfor
  endif
  dd=a+(2*n-1)*h;
  int2+=4.*f(dd);
  
  int+=(int1+int2);
  int*=h/3;

endfunction