function [u,x,y,t] = onda2(a,D,T,it0,i1t0,bxyt,Mx,My,N)
dx = (D(2)- D(1))/Mx; x = D(1)+[0:Mx]*dx;
dy = (D(4)- D(3))/My; y = D(3)+[0:My]'*dy;
dt = T/N; t = [0:N]*dt;
%
u = zeros(My+1,Mx + 1); ut = zeros(My + 1,Mx + 1);
for j = 2:Mx
  for i = 2:My
    u(i,j) = it0(x(j),y(i)); ut(i,j) = i1t0(x(j),y(i));
  end
end
adt2 = a*dt*dt; rx = adt2/(dx*dx); ry = adt2/(dy*dy);
rxy1 = 1- rx - ry; rxy2 = rxy1*2;
u_1 = u;
for k = 0:N
  t = k*dt;
  for i = 1:My + 1 %cc
    u(i,[1 Mx + 1]) = [bxyt(x(1),y(i),t) bxyt(x(Mx + 1),y(i),t)];
  end
  for j = 1:Mx + 1
    u([1 My + 1],j) = [bxyt(x(j),y(1),t); bxyt(x(j),y(My + 1),t)];
  end
  if k == 0
    for i = 2:My
      for j = 2:Mx 
        u(i,j) = 0.5*(rx*(u_1(i,j - 1) + u_1(i,j + 1))...
        + ry*(u_1(i - 1,j)+u_1(i + 1,j))) + rxy1*u(i,j) +dt*ut(i,j);
      end
    end
  else
    for i = 2:My
      for j = 2:Mx 
        u(i,j) = rx*(u_1(i,j - 1)+ u_1(i,j + 1))...
        + ry*(u_1(i - 1,j) + u_1(i + 1,j)) + rxy2*u(i,j) -u_2(i,j);
      end
    end
  end
  u_2 = u_1; u_1 = u; 
  mesh(x,y,u), axis([0 2 0 2 -.1 .1]), pause
end