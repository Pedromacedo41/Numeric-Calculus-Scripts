a = 1; 
it0 = inline('sin(pi*x)','x'); %CI
bx0 = inline('0'); bxf = inline('0'); %CC
xf = 1; M = 25; T = 0.1; N = 100; %r = 0.625
%soluçao analitica
uo = inline('sin(pi*x)*exp(-pi*pi*t)','x','t');
[u1,x,t] = calor_exp(a,xf,T,it0,bx0,bxf,M,N);
figure(1), clf, mesh(t,x,u1)
[u2,x,t] = calor_imp(a,xf,T,it0,bx0,bxf,M,N); 
figure(2), clf, mesh(t,x,u2)
MN = M*N;
Uo = uo(x,t); aUo = abs(Uo)+eps; %valores verdadeiros da soluçao analiticas
err1 = norm((u1-Uo)./aUo)/MN
err2 = norm((u2-Uo)./aUo)/MN
