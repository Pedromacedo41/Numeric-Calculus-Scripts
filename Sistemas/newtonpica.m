function newtonpica
   format long;
   
   syms x1 x2 x3;
   f1=x1^3+x2*x1^2 -x1*x3+6;
   f2=e^x1+e^x2-x3;
   f3=x2^2-2*x1*x3-4;
   F=[f1;f2;f3];
   J=jacobian(F);
  
   x=[-1;-2;1];
   precisao=0.01;
   temp=[1;1;1];
   i=0;
   
   while (max(abs(x-temp)) > precisao)
      A=subs(F,{x1 x2 x3},x');
      A=double(A);
      B=subs(J,{x1 x2 x3},x');
      B=double(B);
      s=-inv(B)*A;
      temp=x;
      x= x+s;
      display(x);
      i++;
   end  
   

end