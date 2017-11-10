
format long

soma = 0;
x=1;
for i =1:10
	n = (x)^(2*i - 1);
	m= (2*i - 1);
	soma= soma + (-1)^(i-1)*n/m;
	p(i) =4*soma;
end 

format long;
soma1 = 0;
soma2 = 0; 
x1=1/5;
x2=1/239;
for i =1:10
	n1 = (x1)^(2*i - 1);
	n2 = (x2)^(2*i - 1);
	m= (2*i - 1);
	soma1= soma1 + (-1)^(i-1)*n1/m;
	soma2= soma2 + (-1)^(i-1)*n2/m;
	p1(i) =4*( 4* soma1 - soma2) ;
end 
 
soma1 = 0;
soma2 = 0; 
x1=1/2;
x2=1/3;
for i =1:10
	n1 = (x1)^(2*i - 1);
	n2 = (x2)^(2*i - 1);
	m= (2*i - 1);
	soma1= soma1 + (-1)^(i-1)*n1/m;
	soma2= soma2 + (-1)^(i-1)*n2/m;
	p2(i) = 4* (soma1 + soma2);
end

soma1 = 0;
soma2 = 0; 
x1=1/3;
x2=1/7;
for i =1:10
	n1 = (x1)^(2*i - 1);
	n2 = (x2)^(2*i - 1);
	m= (2*i - 1);
	soma1= soma1 + (-1)^(i-1)*n1/m;
	soma2= soma2 + (-1)^(i-1)*n2/m;
	p3(i) = 4* (2*soma1 + soma2);
end

soma1 = 0;
soma2 = 0; 
soma3 = 0; 
x1=1/2;
x2=1/5;
x3=1/8;
for i =1:10
	n1 = (x1)^(2*i - 1);
	n2 = (x2)^(2*i - 1);
	n3 = (x3)^(2*i - 1);
	m= (2*i - 1);
	soma1= soma1 + (-1)^(i-1)*n1/m;
	soma2= soma2 + (-1)^(i-1)*n2/m;
	soma3= soma3 + (-1)^(i-1)*n3/m;
	p4(i) = 4* (soma1 + soma2 + soma3);
end

function saida = arctan (n, x)
	soma = 0;
	for i =1:n
		n1 = (x)^(2*i - 1);
		m= (2*i - 1);
		soma= soma + (-1)^(i-1)*n1/m;
	end
endfunction

x= 1:10;
figure;
plot(x,p,'--ys');
hold on;
plot(x,p1,'--ls');
hold on;
plot(x,p2,'--bs');
hold on;
plot(x,p3,'--rs');
hold on;
plot(x,p4,'--gs');
hold 


legend("Aproximacao 1", "Aproximacao 2", "Aproximacao 3","Aproximacao 4", "Aproximacao 5");
title("Aproximacao de pi ");
xlabel("Numero de Iteracoes");




