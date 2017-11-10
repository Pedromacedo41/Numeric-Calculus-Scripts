function roegten
   m=1;
   format long;
   
   n=6; k=6;
   mat=zeros(n,k-1);
   for j= 1:k
     if (j==1)
       for i=1:n
          mat(i,j)=Trapeziorepetida(m*(2^(i-1)));
       endfor
     else
      for t=j:n
        mat(t,j)= (4^(j-1)*mat(t,j-1)-mat(t-1,j-1))/(4^(j-1)-1);
      endfor 
     endif
   endfor
   display(mat);
   
endfunction 

function int = Trapeziorepetida(n)

  a=0;
  b=1;
  
  h=(b-a)/n;
  int=2*sin(b^2)-2*sin(a^2);

  if(n>=2) 
     for i=2:(n)
      x=a+(i-1)*h;
      int+=2*(2*sin(x^2));
     endfor
  endif
  int*=h/2;
  display(int);

endfunction  