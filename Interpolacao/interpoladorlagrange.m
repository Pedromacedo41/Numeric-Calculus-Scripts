function interpoladorlagrange

   format long ;
   x=[0 85 160 226 305 353 412 480 542 615 700 780 870 971 1070 1181 1230 1319 1371 1410 1489 1600 1690 1740 1832 1902 1960];
   y=[10 100 200 300 500 700 1000 1400 1800 2300 2900 3500 4200 5000 5800 6700 7100 7800 8200 8500 9100 9900 10500 10800 11300 11600 11734];
   n=length(x);
 
   for i= 1:n 
     produto=1;
     for j= 1:n
         if (j!=i)
           produto*=(x(i)-x(j));
         endif
     endfor
     denominador(i)=produto;

     produto=1;
     
     for j= 1:n
         if (j!=i)
           produto*=(100-x(j));
         endif
     endfor
     numerador(i)=produto;
     f(i) = (y(i)/denominador(i))*numerador(i);
   
   endfor
  
   display(sum(f));
   
 endfunction
   