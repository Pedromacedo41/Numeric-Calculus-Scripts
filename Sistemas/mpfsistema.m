function OLA
   format long;
   
   syms x1 x2;
   phi1= sqrt(1-x2^2);
   phi2= x1/2;
   
   a1=0.5;
   b1=0.5;
   precisao=0.01;
   temp1=1;
   temp2=1;
   
   while abs(max(a1-temp1,b1-temp2)) > precisao
     temp1=a1;
     temp2=b1;
     a1= double(subs(phi1,b1));
     b1= double(subs(phi2,temp1));
     
   end  
  
   display(a1)
   display(b1);

end

