it0 = inline('0.1*sin(pi*x)*sin(pi*y/2)','x','y'); 
i1t0 = inline('0','x','y'); bxyt = inline('0','x','y','t');
a = .25; D = [0 2 0 2]; T = 2; Mx = 40; My = 40; N = 40;
[u,x,y,t] = onda2(a,D,T,it0,i1t0,bxyt,Mx,My,N);