
function principal
  f=[0.2 0.2 0.2 0.2 0.2 0.2 0.2 0.2 0.2 0.2];
  
  n=5;
  a=0;
  b=1;
  h=(b-a)/(2*n);
  int=f(1)+f(2*n);    
  int1=0;
  int2=0;
  
  if (n>=2)
    for i=1:(n-1)
      int1+=2*f(2*i);
      int2+=4*f(2*i-1);
    endfor
  endif
  
  int2+=4*f(2*n-1);
  
  int+=(int1+int2);
  int/=3;
  display(int);

endfunction


