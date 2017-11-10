function interpolador
   pkg load symbolic;
   syms X numerador f;
   x=[0.40 0.52 0.60];
   y=[0 .27 0.29 0.32];
   n=length(x);
 
   for i= 1:n 
     produto=1;
     for j= 1:n
         if (j!=i)
           produto*=(x(i)-x(j));
         endif
     endfor
     denominador(i)=(produto);

     produto=1;
     
     for j= 1:n
         if (j!=i)
           produto=mtimes(produto,(X-x(j)));
         endif
     endfor
     numerador(i)=produto;
     f(i) = (y(i)/denominador(i))*numerador(i);
     
   endfor
   
   display(f);
   display(sum(f));
 
 endfunction
   