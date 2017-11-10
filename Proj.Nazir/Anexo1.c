
//#include <vcl\condefs.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#pragma hdrstop


int main(int argc, char **argv)
{
	double InterpCd (double Cd[2][25], double X);
	double Cdp (double Ro, double S, double Cd, double M);
	double Vtil (double Vx, double Vy, double Vz, double Wx, double Wy, double Wz);
	double Ro (double Altitude);
	double VSom (double Temperatura, double Altura);
	double Mach (double Temperatura, double Altura, double VTIL);
	double XFUN (double UU,double VV,double WW,double CDP);
	double YFUN (double UU,double VV,double WW,double CDP,double G);
	double ZFUN (double UU,double VV,double WW,double CDP);
	double RAD (double MIL);
	double TT,XX,YY,ZZ,UU,VV,WW,H,XA,YA,ZA;
	double K1,L1,M1,N1,O1,P1;
	double K2,L2,M2,N2,O2,P2;
	double K3,L3,M3,N3,O3,P3;
	double K4,L4,M4,N4,O4,P4;
	double M, S, Wx, Wy, Wz, V0, FI, TETA, X0, Y0, Z0,G;
	double Vx, Vy, Vz, MACH, TempFahr,CDP;

    FILE *arqsaida;
	arqsaida=fopen("Saida.txt","w");

	/*--------DADOS DA MUNIÇÃO-----------*/
	M = 14.970;
	S = M_PI*0.10485*0.10485/4;

	double Cdtab[2][25] = {{0,0.6,0.7,0.75,0.8,0.85,0.875,0.9,0.925,0.95,0.975,1,1.025,1.05,1.1,1.2,1.35,1.5,1.75,2,2.25,2.5,3,3.5,1000,
	},{0.13,0.13,0.12,0.117,0.115,0.115,0.118,0.125,0.145,0.185,0.26,0.337,0.385,0.415,0.415,0.405,0.39,0.375,0.357,0.34,
		0.323,0.305,0.27,0,0}};

	/*----------------------------------*/
	/*-------DADOS METEOROLÓGICOS-------*/
	Wx = 0;
	Wy = 0;
	Wz = 0;
	G = 9.81;
	TempFahr = 59;


	/*----------------------------------*/
	/*---------DADOS DO TIRO------------*/

	V0 = 464.8;
	printf ("TRAJETOGRAFO PARA 105mm M1\n\n");
	printf ("Insira o angulo de elevacao: ");
	scanf("%lf",&FI);
	printf ("Insira o angulo de deriva: ");
	scanf("%lf",&TETA);
	X0 = Y0 = Z0 = 0;

	/*----------------------------------*/
	H = 0.01;

	 /* INCREMENTO DESEJADO DE TEMPO */
	/*-DEFINIÇÃO DAS CONDIÇÒES INICIAIS-*/

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
	/*----------------------------------*/

	while (YY>=0) { /* CONDIÇÃO DE TÉRMINO DE TRAJETÓRIA */
		XA = XX;
		YA = YY;
		ZA = ZZ;
		MACH = Mach(TempFahr,YY,sqrt(UU*UU+VV*VV+WW*WW));
		CDP = Cdp(Ro(YY),S,InterpCd(Cdtab,MACH),M);
		/* -----BLOCO RUNGE-KUTTA 4a. ORDEM ------*/
		K1 = H*UU;
		L1 = H*XFUN(UU,VV,WW,CDP);
		M1 = H*VV;
		N1 = H*YFUN(UU,VV,WW,CDP,G);
		O1 = H*WW;
		P1 = H*ZFUN(UU,VV,WW,CDP);
		K2 = H*(UU+L1/2);
		L2 = H*XFUN(UU+L1/2,VV+N1/2,WW+P1/2,CDP);
		M2 = H*(VV+N1/2);
		N2 = H*YFUN(UU+L1/2,VV+N1/2,WW+P1/2,CDP,G);
		O2 = H*(WW+P1/2);
		P2 = H*ZFUN(UU+L1/2,VV+N1/2,WW+P1/2,CDP);
		K3 = H*(UU+L2/2);
		L3 = H*XFUN(UU+L2/2,VV+N2/2,WW+P2/2,CDP);
		M3 = H*(VV+N2/2);
		N3 = H*YFUN(UU+L2/2,VV+N2/2,WW+P2/2,CDP,G);
		O3 = H*(WW+P2/2);
		P3 = H*ZFUN(UU+L2/2,VV+N2/2,WW+P2/2,CDP);
		K4 = H*(UU+L3);
		L4 = H*XFUN(UU+L3,VV+N3,WW+P3,CDP);
		M4 = H*(VV+N3);
		N4 = H*YFUN(UU+L3,VV+N3,WW+P3,CDP,G);
		O4 = H*(WW+P3);
		P4 = H*ZFUN(UU+L3,VV+N3,WW+P3,CDP);
		TT = TT+H;
		XX = XX+(K1+2*(K2+K3)+K4)/6+Wx*H; /* CORREÇÃO DEVIDA AO VENTO */
		UU = UU+(L1+2*(L2+L3)+L4)/6;
		YY = YY+(M1+2*(M2+M3)+M4)/6+Wy*H; /* CORREÇÃO DEVIDA AO VENTO */
		VV = VV+(N1+2*(N2+N3)+N4)/6;
		ZZ = ZZ+(O1+2*(O2+O3)+O4)/6+Wz*H; /* CORREÇÃO DEVIDA AO VENTO */
		WW = WW+(P1+2*(P2+P3)+P4)/6;
		/*----------------------------------------*/
		YY = YY+((XX-XA)*(XX-XA)+(ZZ-ZA)*(ZZ-ZA))/12713532; /* CORREÇÃO DEVIDA À CURVATURA DA TERRA */
		G = G-2*G*(YY-YA)/6356766;

		/* ATUALIZAÇÃO DA GRAVIDADE */
		fprintf (arqsaida,"%lf\t%lf\t%lf\t%lf\t%lf\n",TT,XX,YY,ZZ,VV);
	}

	fclose(arqsaida);
	return (0);
}

double InterpCd (double Cd[2][25], double X)
{
	int i;
	double DEN, A, B, Y;
	i = 0;
	while (Cd[0][i] <= X) i = i+1;
	DEN = Cd[0][i]-Cd[0][i-1];
	A = (Cd[1][i]-Cd[1][i-1])/DEN;
	B = (Cd[0][i]*Cd[1][i-1]-Cd[0][i-1]*Cd[1][i])/DEN;
	Y = A*X+B;
	return (Y);
}


double Cdp (double Ro, double S, double Cd, double M)
{
	double CDP;
	CDP = Ro*S*Cd*0.5/M;
	return (CDP);
}

double Vtil (double Vx, double Vy, double Vz, double Wx, double Wy, double Wz)
{
	double VTIL;
	VTIL = sqrt(pow(Vx-Wx,2)+pow(Vy-Wy,2)+pow(Vz-Wz,2));
	return (VTIL);
}

double Ro (double Altitude)
{
	double RO,h;
	h = 2.926*pow10(-5)+pow10(-10)*(Altitude/(12*0.0254));
	RO = 0.0764742*exp(-Altitude/(12*.0254)*h);
	return(16.018463374*RO);
}

double VSom (double Temperatura, double Altura)
{

	double VSOM,K,TempeAlt;

	K = pow10(-6)*6.858+(2.776*pow10(-11))*Altura/(12*0.0254);
	TempeAlt = (Temperatura+459.67)*exp(-K*Altura/(12*0.0254))-459.67;
	VSOM = 49.0223*sqrt(TempeAlt+459.67);
	return (VSOM*0.3048);
}


double Mach (double Temperatura, double Altura, double VTIL)
{
	return (VTIL/VSom(Temperatura,Altura));
}


double XFUN (double UU,double VV,double WW,double CDP)
{
	return(-CDP*sqrt(UU*UU+VV*VV+WW*WW)*UU);
}


double YFUN (double UU,double VV,double WW,double CDP,double G)
{
	return(-CDP*sqrt(UU*UU+VV*VV+WW*WW)*VV-G);
}

double ZFUN (double UU,double VV,double WW,double CDP)
{
	return(-CDP*sqrt(UU*UU+VV*VV+WW*WW)*WW);
}


double RAD(double MIL)
{
	return (MIL*M_PI/3200);
}
