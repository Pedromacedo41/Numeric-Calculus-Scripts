format long;

function alpha = criteriodaslinhas (A)
   dim=3;
   for i= 1:dim
     soma=0;
     for j=1:dim
       if j==i continue;
          else 
           soma+= abs(A(i,j)/A(i,i));
       endif
     end
     a(i)=soma;
   end
   alpha = (max(a)<1);
end

function solucao = gaussJacobi(A,dim,b,x0,precisao)
   for i=1:dim
     for j=1:dim
        if (j==i) C(i,j)=0;
           else
             C(i,j)= -A(i,j)/A(i,i);
        end
     end
   end
   
   for i=1:dim
      g(i)=b(i)/A(i,i);
   end

   temp=ones(1,dim);
   
   while abs(max(temp-x0)/max(temp)) > precisao
      temp=x0;
      x0=C*(x0)+(g');
   end
   solucao=x0;
   
end






    