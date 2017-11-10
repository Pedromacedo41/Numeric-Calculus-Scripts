function interpoladornewton
   
   syms X numerador g;
   x=[0.40 0.52 0.60];
   f=[0.27 0.29 0.32];
   n=length(x);
   A=zeros(n,n);
   A(1,:)=f; 

   for i=2:n
     for j=i:n
       A(i,j)=(A(i-1,j-1)-A(i-1,j))/(x(j-i+1)-x(j));
     end
   end
   A' 
   g(1)=f(1);
   
   for i= 2:n 
     produto=1;
     for j= 1:(i-1)
         produto*=(X-x(j));
     endfor
     g(i)=(produto);
   endfor
   
   display(g');
   display(sum(g));
   
  
 endfunction