%Metodo da Bissecao

precisao = 0.0001;
format long;

function raiz = Bissecao (a1,b, precisao)  
    syms x;
    f=cos(x)-x     %para a funca x-cosx
	  while (b-a1) > precisao
        c=(a1+b)/2;
        if (double(subs(f,x, a1)))*(double(subs(f,x, c))) > 0
            a1=c;
           else 
            b=c;
        endif
    endwhile
    raiz = (a1+b)/2;
endfunction


fprintf("Raiz aproximada: %d" , Bissecao(0,1,precisao));


     
