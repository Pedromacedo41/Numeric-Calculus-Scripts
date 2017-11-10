function pvclinear2

   f= @(x) x;
   a= 2;
   b= 1;
   limitea=0;
   limiteb=1;
   n=4;
   h=(limiteb-limitea)/n;
   
   
   
   
  

   display(gaussJacobi(A,b,x0));

endfunction

function solucao = gaussJacobi(A,b,x0)
   dim = 3;
   precisao= 0.0001;
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



