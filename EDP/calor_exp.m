function [u,x,t] = calor_exp(a,xf,T,it0,bx0,bxf,M,N)
dx = xf/M; x = [0:M]'*dx;
dt = T/N; t = [0:N]*dt;
for i = 1:M + 1, u(i,1) = it0(x(i)); end
for n = 1:N + 1, u([1 M + 1],n) = [bx0(t(n)); bxf(t(n))]; end
r = a*dt/dx/dx, r1 = 1 - 2*r;
for k = 1:N
  for i = 2:M
    u(i,k+1) = r*(u(i + 1,k) + u(i-1,k)) + r1*u(i,k);
  end
end