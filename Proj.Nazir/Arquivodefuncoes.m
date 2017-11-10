1;

function Y = InterpCd (Cd,X)  %Substitui todas as funcoes InterAlgumacoisa
	j = 1;
  n = size(Cd)(1,2);
	while (Cd(1,j) <= X && j<n)
    j = j+1;
  endwhile
	DEN = Cd(1,j)-Cd(1,j-1);
	A = (Cd(2,j)-Cd(2,j-1))/DEN;
	B = (Cd(1,j)*Cd(2,j-1)-Cd(1,j-1)*Cd(2,j))/DEN;
	Y = A*X+B;
	
endfunction

function d = pow(a,b)
  d = a^b;
endfunction

function d = pow10(a)
  d=10^a;
 endfunction


 function  VTIL = Vtil (Vx, Vy, Vz, Wx, Wy, Wz)
	VTIL = sqrt(pow(Vx-Wx,2)+pow(Vy-Wy,2)+pow(Vz-Wz,2));
endfunction

function Numero = Ro (Altitude)
	h = 2.926*pow10(-5)+pow10(-10)*(Altitude/(12*0.0254));
	RO = 0.0765*exp(-Altitude/(12*.0254)*h);
	Numero = (16.02*RO); % 18463374*RO;
endfunction
 
function Numero = VSom (Temperatura, Altura)
	K = pow10(-6)*6.858+(2.776*pow10(-11))*Altura/(12*0.0254);
	TempeAlt = (Temperatura+459.67)*exp(-K*Altura/(12*0.0254))-459.67;
	VSOM = 49.0223*sqrt(TempeAlt+459.67);
	Numero = (VSOM*0.3048);
endfunction

function Numero = Mach (Temperatura, Altura, VTIL)
	Numero = VTIL/VSom(Temperatura,Altura);
endfunction

function Numero = RAD( MIL)
	Numero = (MIL*pi/3200);
endfunction

function Numero = ka (Ro,S,M)
	KA = Ro*S*0.5/M;
	Numero = (KA);
endfunction

function Numero = Cdp (Ro, S,Cd, M)
	CDP = Ro*S*Cd*0.5/M;
	Numero = (CDP);
endfunction

function Numero = XFUN (UU,VV,WW,CDP)
	Numero =(-CDP*sqrt(UU*UU+VV*VV+WW*WW)*UU);
endfunction

function Numero = YFUN (UU,VV, WW,CDP,G)
	Numero =(-CDP*sqrt(UU*UU+VV*VV+WW*WW)*VV-G);
endfunction

function Numero = ZFUN (UU,VV,WW,CDP)
	Numero =(-CDP*sqrt(UU*UU+VV*VV+WW*WW)*WW);
endfunction

function Numero = XFUN2(UU,VV,WW,PP,KA,KB,dgir,CD,CLA,CMA,CNPA,G,OM,L,AZ)
	Numero = (-KA*CD*sqrt(UU*UU+VV*VV+WW*WW)*UU+KB*CLA/CMA/(UU*UU+VV*VV+WW*WW)*PP*(-
	G*WW)+KB*CNPA/CMA*dgir*PP*PP/(UU*UU+VV*VV+WW*WW)/(UU*UU+VV*VV+WW*WW)*(G*VV*UU)+2*OM*(-
	VV*cos(L)*sin(AZ)-WW*sin(L)));
endfunction

function Numero = YFUN2 (UU,VV,WW,PP,KA,KB,dgir,CD,CLA,CMA,CNPA,G,OM,L,AZ)
	Numero =(-
	KA*CD*sqrt(UU*UU+VV*VV+WW*WW)*VV+KB*CNPA/CMA*dgir*PP*PP/(UU*UU+VV*VV+WW*WW)/(UU*UU+VV*VV+
	WW*WW)*(-G*(UU*UU+WW*WW))-G+2*OM*(UU*cos(L)*sin(AZ)+WW*cos(L)*cos(AZ)));
endfunction

function Numero = ZFUN2 (UU,VV,WW,PP,KA,KB,dgir,CD,CLA,CMA,CNPA,G,OM,L,AZ)
	Numero =(-
	KA*CD*sqrt(UU*UU+VV*VV+WW*WW)*WW+KB*CLA/CMA/(UU*UU+VV*VV+WW*WW)*PP*(G*UU)+KB*CNPA/CMA*
	dgir*PP*PP/(UU*UU+VV*VV+WW*WW)/(UU*UU+VV*VV+WW*WW)*(G*VV*WW)+2*OM*(UU*sin(L)-VV*cos(L)*cos(AZ)));
endfunction

function Numero = PFUN (UU,VV,WW,PP,KA,KB,dgir,M,IX,CLP)
	Numero =(KA*M/IX*dgir*dgir*sqrt(UU*UU+VV*VV+WW*WW)*PP*CLP);
endfunction

function Numero = XFUN3 (UU,VV,WW,H1,H2,H3,X1,X2,X3,CO1,DGIR,PP,G,CD,CLA,CNPA,CNQ,CNA)
	Numero = (-CD*CO1*sqrt(UU*UU+VV*VV+WW*WW)*UU+CLA*CO1*((UU*UU+VV*VV+WW*WW)*X1-UU*(UU*X1+VV*X2+WW*X3))-CNPA*CO1*DGIR*PP*(X2*WW-X3*VV)+(CNQ+CNA)*CO1*DGIR*sqrt(UU*UU+VV*VV+WW*WW)*(H2*X3-H3*X2));
endfunction

function Numero = YFUN3(UU,VV,WW,H1,H2,H3,X1,X2,X3,CO1,DGIR,PP,G,CD,CLA,CNPA,CNQ,CNA)
	Numero = (-CD*CO1*sqrt(UU*UU+VV*VV+WW*WW)*VV+CLA*CO1*((UU*UU+VV*VV+WW*WW)*X2-
	VV*(UU*X1+VV*X2+WW*X3))-CNPA*CO1*DGIR*PP*(X3*UU-
	X1*WW)+(CNQ+CNA)*CO1*DGIR*sqrt(UU*UU+VV*VV+WW*WW)*(H3*X1-H1*X3)-G);
endfunction

function Numero = ZFUN3 (UU,VV,WW,H1,H2,H3,X1,X2,X3,CO1,DGIR,PP,G,CD,CLA,CNPA,CNQ,CNA)
	Numero = (-CD*CO1*sqrt(UU*UU+VV*VV+WW*WW)*WW+CLA*CO1*((UU*UU+VV*VV+WW*WW)*X3-
	WW*(UU*X1+VV*X2+WW*X3))-CNPA*CO1*DGIR*PP*(X1*VV-
	X2*UU)+(CNQ+CNA)*CO1*DGIR*sqrt(UU*UU+VV*VV+WW*WW)*(H1*X2-H2*X1));
endfunction

function Numero = H1FUN (UU,VV,WW,H1,H2,H3,X1,X2,X3,CO2,DGIR,Ix,Iy,PP,CLP,CMA,CMPA,CMQ,CMG)
	Numero = (CLP*CO2*DGIR*PP*sqrt(UU*UU+VV*VV+WW*WW)*X1+CMA*CO2*sqrt(UU*UU+VV*VV+WW*WW)*(VV*X3-
	WW*X2)+CMPA*CO2*DGIR*PP*((X1*X1+X2*X2+X3*X3)*UU-
	X1*(UU*X1+VV*X2+WW*X3))+(CMQ+CMG)*CO2*DGIR*sqrt(UU*UU+VV*VV+WW*WW)*((X1*X1+X2*X2+X3*X3)*H1-
	Ix/Iy*PP*X1));
endfunction

function Numero = H2FUN (UU,VV,WW,H1,H2,H3,X1,X2,X3,CO2,DGIR,Ix,Iy,PP,CLP,CMA,CMPA,CMQ,CMG)
	Numero = (CLP*CO2*DGIR*PP*sqrt(UU*UU+VV*VV+WW*WW)*X2+CMA*CO2*sqrt(UU*UU+VV*VV+WW*WW)*(WW*X1-
	UU*X3)+CMPA*CO2*DGIR*PP*((X1*X1+X2*X2+X3*X3)*VV-
	X2*(UU*X1+VV*X2+WW*X3))+(CMQ+CMG)*CO2*DGIR*sqrt(UU*UU+VV*VV+WW*WW)*((X1*X1+X2*X2+X3*X3)*H2-
	Ix/Iy*PP*X2));
endfunction

function Numero = H3FUN (UU,VV,WW,H1,H2,H3,X1,X2,X3,CO2,DGIR,Ix,Iy,PP,CLP,CMA,CMPA,CMQ,CMG)
	Numero = (CLP*CO2*DGIR*PP*sqrt(UU*UU+VV*VV+WW*WW)*X3+CMA*CO2*sqrt(UU*UU+VV*VV+WW*WW)*(UU*X2-
	VV*X1)+CMPA*CO2*DGIR*PP*((X1*X1+X2*X2+X3*X3)*WW-
	X3*(UU*X1+VV*X2+WW*X3))+(CMQ+CMG)*CO2*DGIR*sqrt(UU*UU+VV*VV+WW*WW)*((X1*X1+X2*X2+X3*X3)*H3-
	Ix/Iy*PP*X3));
endfunction

function Numero = X1FUN (H1,H2,H3,X1,X2,X3)
	Numero = (H2*X3-H3*X2);
endfunction

function Numero = X2FUN (H1,H2,H3,X1,X2,X3)
	Numero = (H3*X1-H1*X3);
endfunction

function Numero = X3FUN (H1,H2,H3,X1,X2,X3)
	Numero = (H1*X2-H2*X1);
endfunction