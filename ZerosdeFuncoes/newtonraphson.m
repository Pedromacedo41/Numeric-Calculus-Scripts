function newtonraphson

    syms x;
    f=e^x-2*cos(x);
    a=0.5;
    temp=1;
    h=x-f/(diff(f));
    precisao=0.0001;
    while abs(temp-a)>precisao;
        temp=a;
        a= double(subs(h,a));
    end
    disp(a);
end
%Exemplo para f: exp(x)-2*cos(x) ; erro=0001; x0=0.5;