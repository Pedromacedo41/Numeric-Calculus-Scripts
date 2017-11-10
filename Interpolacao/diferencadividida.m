
function diferencadividida

  x=[0.34 0.40 0.52 2 3];
  f=[0.22 0.27 0.29 5 6];
  n=length(x);
  A=zeros(n,n);
  A(1,:)=f; 

  for i=2:n
    for j=i:n
      A(i,j)=(A(i-1,j-1)-A(i-1,j))/(x(j-i+1)-x(j));
    end
  end
  A' 
  
end
 
 
      