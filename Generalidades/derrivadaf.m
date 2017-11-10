x = 1.0; %% valor inicial
precisao = 0.0001;

function d = f(x)              %%funcao a determinar a raiz
  d=e^x-2*cos(x);
endfunction

function d = derivadaf(x)
  d=e^x+2*sin(x);
endfunction

while (f(x) > precisao)
    if (derivadaf(x) ==0 )
        else x=x-f(x)/derivadaf(x);
    endif
endwhile;

display('O valor da raiz e %.5f' , x);
  
 
 