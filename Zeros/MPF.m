function MPF
    syms x;
    f=sqrt(6-x);
    a=1.5;
    temp=1;
    precisao=0.0001;
    while abs(temp-a)>precisao
     temp =a;
     a=double(subs(f,a));
    end
    disp(a);
end