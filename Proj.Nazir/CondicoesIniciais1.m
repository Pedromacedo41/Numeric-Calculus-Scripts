% Dados da Muniçao 
M = 14.970;
S = pi*0.10485*0.10485/4;

Cdtab = [0,0.6,0.7,0.75,0.8,0.85,0.875,0.9,0.925,0.95,0.975,1,1.025,1.05,1.1,1.2,1.35,1.5,1.75,2,2.25,2.5,3,3.5,1000,
	;0.13,0.13,0.12,0.117,0.115,0.115,0.118,0.125,0.145,0.185,0.26,0.337,0.385,0.415,0.415,0.405,0.39,0.375,0.357,0.34,0.323,0.305,0.27,0,0];

% Dados Meteorologicos
Wx = 0;
Wy = 0;
Wz = 0;
G = 9.81;
TempFahr = 59;

% Dados do Tiro
V0 = 464.8;
FI = input("TRAJETOGRAFO PARA 105mm M1\n\nInsira o angulo de elevacao:");
TETA = input("Insira o angulo de deriva: ");
X0 = Y0 = Z0 = 0;

% Incremento Desejado de Tempo
H = 0.01;

% Definiçao das condicoes iniciais 
Vx = V0*cos(RAD(FI))*cos(RAD(TETA));
Vy = V0*sin(RAD(FI))*cos(RAD(TETA));
Vz = V0*sin(RAD(TETA));
TT = 0;
XX = X0;
YY = Y0;
ZZ = Z0;
UU = Vx-Wx;
VV = Vy-Wy;
WW = Vz-Wz;