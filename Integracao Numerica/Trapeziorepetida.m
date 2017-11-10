

function Trapeziorepetida
  n=1000;
  a=0;
  b=1;
  
  h=(b-a)/n;
  int=-6*(a^5+b^5)+12;
  if(n>=2) 
     for i=2:(n)
      x=a+(i-1)*h;
      
      int+=2*(6-6*(x^5));   
     endfor
  endif
  int*=h/2;
  display(int);

endfunction