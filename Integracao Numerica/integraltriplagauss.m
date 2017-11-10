function integraltriplagauss
%Inserir funcaoo em f(x,y):
    f=@(x,y,z) sqrt(x*y*z);%funcao a ser integrada
    c=@(x)0; %limite de integracao inferior c(x)
    d=@(x) sqrt(4-x*x);  %limite de integracao superior d(x)
    e=@(x,y)sqrt(4-x*x-y*y); %limite de integracao inferior e(x,y);
    g=@(x,y)8-x-y; %limite de integracao superior g(x,y);
    
R= [0 0 0 0 0;0.5773502692 -0.5773502692 0 0 0;0.7745966692 0 -0.7745966692 0 0; 0.8611363116 0.3399810436 -0.3399810436 -0.8611363116 0; 0.9061798459 0.5384693101 0 -0.5384693101 -0.9061798459];%Raizes
C= [0 0 0 0 0;1 1 0 0 0;0.5555555556 0.8888888889 0.5555555556 0 0;0.3478548451 0.6521451549 0.6521451549 0.3478548451 0;0.2369268850 0.4786286705 0.5688888889 0.4786286705 0.2369268850];%coeficientes
a=0; %inicio do intervalo
b=2; %fim do intervalo


n=5; %numero de subintervalos em x
m=5; %numero de subintervalos em y
p=5; %numero de subintervalos em z

%1� 
h1=(b-a)/2;
h2=(b+a)/2;
J=0;
%2�  
for i=1:m
    %3� 
    JX=0;
    x=h1*R(m,i)+h2;
    d1=d(x);
    c1=c(x);
    k1=(d1-c1)/2;
    k2=(d1+c1)/2;
    %4� Passo
    for j=1:n
        %5� 
        JY=0;
        y=k1*R(n,j)+k2;
        g1=g(x,y);
        e1=e(x,y);
        l1=(g1-e1)/2;
        l2=(g1+e1)/2;
        %6� 
        for k=1:p
            z=l1*R(p,k)+l2;
            Q=f(x,y,z);
            JY=JY+C(p,k)*Q;
        end
        %7�
        JX=JX+C(n,j)*l1*JY;
    end
    %8�
    J=J+C(m,i)*k1*JX;
end
%9� 
J=h1*J;
J
end
    