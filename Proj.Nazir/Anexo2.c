// #include <vcl\condefs.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#pragma hdrstop


int main(int argc, char **argv)
{
	double InterpCd (double Cd[2][25], double X);
	double InterpCna (double Cna[2][22], double X);
	double InterpCnpa (double Cnpa[2][16], double X);
	double InterpClp (double Clp[2][14], double X);
	double InterpCma (double Cma[2][25], double X);
	double ka (double Ro, double S, double M);
	double Vtil (double Vx, double Vy, double Vz, double Wx, double Wy, double Wz);
	double Ro (double Altitude);
	double VSom (double Temperatura, double Altura);
	double Mach (double Temperatura, double Altura, double VTIL);
	double XFUN (double UU,double VV,double WW,double PP,double KA,double KB,double dgir,double CD,double
	CLA,double CMA,double CNPA,double G,double OM,double L,double AZ);

	double YFUN (double UU,double VV,double WW,double PP,double KA,double KB,double dgir,double CD,double
	CLA,double CMA,double CNPA,double G,double OM,double L,double AZ);

	double ZFUN (double UU,double VV,double WW,double PP,double KA,double KB,double dgir,double CD,double
	CLA,double CMA,double CNPA,double G,double OM,double L,double AZ);

	double PFUN (double UU,double VV,double WW,double PP,double KA,double KB,double dgir,double M,double
	IX,double CLP);
	
	double RAD (double MIL);

	double TT,XX,YY,ZZ,UU,VV,WW,RR,PP,H,XA,YA,ZA,FLECHA;
	double K1,L1,M1,N1,O1,P1,Q1,R1;
	double K2,L2,M2,N2,O2,P2,Q2,R2;
	double K3,L3,M3,N3,O3,P3,Q3,R3;
	double K4,L4,M4,N4,O4,P4,Q4,R4;
	double M, S, dgir, IX, Wx, Wy, Wz, V0, FI, TETA, X0, Y0, Z0, P0, G;
	double Vx, Vy, Vz, MACH, TempFahr, KA, KB;
	double CD,CLA,CMA,CNPA,CLP,alfae;
	double OM,L,AZ;

	FILE *arqsaida;
	arqsaida=fopen("saida2.txt","w");
	/*--------DADOS DA MUNIÇÃO-----------*/
	IX = 0.023;
	dgir = 0.10485;
	M = 14.9698;
	S = M_PI*0.10485*0.10485/4;

	double Cdtab[2][25] =
	{0,0.6,0.7,0.75,0.8,0.85,0.875,0.9,0.925,0.95,0.975,1,1.025,1.05,1.1,1.2,1.35,1.5,1.75,2,2.25,2.5,3,3.5,1000,
0.13,0.13,0.12,0.117,0.115,0.115,0.118,0.125,0.145,0.185,0.26,0.337,0.385,0.415,0.415,0.405,0.39,0.375,0.357,0.34,0.323,0.305,0.27,0,0};
	
	double Cnatab[2][22] = {0,0.7,0.75,0.8,0.85,0.875,0.9,0.925,0.975,1,1.025,1.05,1.1,1.2,1.35,1.5,1.75,2,2.25,2.5,3,1000,
1.45,1.45,1.5,1.53,1.56,1.59,1.63,1.65,1.65,1.7,1.8,1.9,2,2.15,2.4,2.5,2.55,2.6,2.7,2.75,0,0};

	double Cnpatab[2][16] = {0,0.8,0.85,0.875,0.9,0.925,0.95,0.975,1,1.025,1.05,1.1,1.2,2.5,3,1000,
-0.8,-0.8,-0.84,-0.87,-0.89,-1.01,-1.13,-1.08,-1.03,-0.99,-0.94,-0.89,-0.8,-0.8,0,0};
	double Clptab[2][14] = {0,0.75,0.8,0.85,0.95,0.975,1,1.025,1.05,1.1,1.2,1.35,1.5,1000,
-0.028,-0.028,-0.0279,-0.0278,-0.0274,-0.0272,-0.0268,-0.0264,-0.026,-0.0256,-0.0248,-0.0246,-0.0245,-0.0245};

	double Cmatab[2][25] =
{0,0.01,0.4,0.6,0.7,0.75,0.8,0.85,0.875,0.9,0.925,0.95,0.975,1,1.025,1.05,1.1,1.2,1.35,1.5,1.75,2,2.25,2.5,1000,
3.45,3.45,3.549,3.6,3.7,3.75,3.85,3.97,4.1,4.3,4.6,4.7,4.4,4.1,3.98,3.93,3.85,3.78,3.67,3.6,3.525,3.45,3.325,3.2,3.2};

	/*----------------------------------*/
	/*-------DADOS METEOROLÓGICOS-------*/
	Wx = 0;
	Wy = 0;
	Wz = 0;
	G = 9.81;
	TempFahr = 59;
	OM = 0;//0.00007292;

	/*----------------------------------*/
	/*---------DADOS DO TIRO------------*/
	V0 = 464.8;
	P0 = 1545;
	L = -45*M_PI/180;
	AZ = -90*M_PI/180;
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
	FLECHA = 0;
	XX = X0;
	YY = Y0;
	ZZ = Z0;
	UU = Vx-Wx;
	VV = Vy-Wy;
	WW = Vz-Wz;
	RR = 0;
	PP = P0;

	/*----------------------------------*/
	while (YY>=0) { /* CONDIÇÃO DE TÉRMINO DE TRAJETÓRIA */
		XA = XX;
		YA = YY;
		ZA = ZZ;
		MACH = Mach(TempFahr,YY,sqrt(UU*UU+VV*VV+WW*WW));
		CD = InterpCd(Cdtab,MACH);
		CLA = InterpCna(Cnatab, MACH)+CD;
		CMA = InterpCma(Cmatab,MACH);
		CNPA = InterpCnpa(Cnpatab,MACH)/2;
		CLP = InterpClp(Clptab,MACH)/2;
		KA = ka(Ro(YY),S,M);
		KB = IX/M/dgir;
		alfae =
		2*IX*PP/(Ro(YY)*S*dgir*(UU*UU+VV*VV+WW*WW)*(UU*UU+VV*VV+WW*WW)*CMA)*G*sqrt(WW*WW+UU*UU);
		/* -----BLOCO RUNGE-KUTTA 4a. ORDEM ------*/
		K1 = H*UU;
		L1 = H*XFUN(UU,VV,WW,PP,KA,KB,dgir,CD,CLA,CMA,CNPA,G,OM,L,AZ);
		M1 = H*VV;
		N1 = H*YFUN(UU,VV,WW,PP,KA,KB,dgir,CD,CLA,CMA,CNPA,G,OM,L,AZ);
		O1 = H*WW;
		P1 = H*ZFUN(UU,VV,WW,PP,KA,KB,dgir,CD,CLA,CMA,CNPA,G,OM,L,AZ);
		Q1 = H*PP;
		R1 = H*PFUN(UU,VV,WW,PP,KA,KB,dgir,M,IX,CLP);
		K2 = H*(UU+L1/2);
		L2 = H*XFUN(UU+L1/2,VV+N1/2,WW+P1/2,PP+R1/2,KA,KB,dgir,CD,CLA,CMA,CNPA,G,OM,L,AZ);
		M2 = H*(VV+N1/2);
		N2 = H*YFUN(UU+L1/2,VV+N1/2,WW+P1/2,PP+R1/2,KA,KB,dgir,CD,CLA,CMA,CNPA,G,OM,L,AZ);
		O2 = H*(WW+P1/2);
		P2 = H*ZFUN(UU+L1/2,VV+N1/2,WW+P1/2,PP+R1/2,KA,KB,dgir,CD,CLA,CMA,CNPA,G,OM,L,AZ);
		Q2 = H*(PP+R1/2);
		R2 = H*PFUN(UU+L1/2,VV+N1/2,WW+P1/2,PP+R1/2,KA,KB,dgir,M,IX,CLP);
		K3 = H*(UU+L2/2);
		L3 = H*XFUN(UU+L2/2,VV+N2/2,WW+P2/2,PP+R2/2,KA,KB,dgir,CD,CLA,CMA,CNPA,G,OM,L,AZ);
		M3 = H*(VV+N2/2);
		N3 = H*YFUN(UU+L2/2,VV+N2/2,WW+P2/2,PP+R2/2,KA,KB,dgir,CD,CLA,CMA,CNPA,G,OM,L,AZ);
		O3 = H*(WW+P2/2);
		P3 = H*ZFUN(UU+L2/2,VV+N2/2,WW+P2/2,PP+R2/2,KA,KB,dgir,CD,CLA,CMA,CNPA,G,OM,L,AZ);
		Q3 = H*(PP+R2/2);
		R3 = H*PFUN(UU+L2/2,VV+N2/2,WW+P2/2,PP+R2/2,KA,KB,dgir,M,IX,CLP);
		K4 = H*(UU+L3);
		L4 = H*XFUN(UU+L3,VV+N3,WW+P3,PP+R3,KA,KB,dgir,CD,CLA,CMA,CNPA,G,OM,L,AZ);
		M4 = H*(VV+N3);
		N4 = H*YFUN(UU+L3,VV+N3,WW+P3,PP+R3,KA,KB,dgir,CD,CLA,CMA,CNPA,G,OM,L,AZ);
		O4 = H*(WW+P3);
		P4 = H*ZFUN(UU+L3,VV+N3,WW+P3,PP+R3,KA,KB,dgir,CD,CLA,CMA,CNPA,G,OM,L,AZ);
		Q4 = H*(PP+R3);
		R4 = H*PFUN(UU+L3,VV+N3,WW+P3,PP+R3,KA,KB,dgir,M,IX,CLP);
		TT = TT+H;
		XX = XX+(K1+2*(K2+K3)+K4)/6+Wx*H; /* CORREÇÃO DEVIDA AO VENTO */
		UU = UU+(L1+2*(L2+L3)+L4)/6;
		YY = YY+(M1+2*(M2+M3)+M4)/6+Wy*H; /* CORREÇÃO DEVIDA AO VENTO */
		if (((M1+2*(M2+M3)+M4)/6)>0) FLECHA = YY;
		VV = VV+(N1+2*(N2+N3)+N4)/6;
		ZZ = ZZ+(O1+2*(O2+O3)+O4)/6+Wz*H; /* CORREÇÃO DEVIDA AO VENTO */
		WW = WW+(P1+2*(P2+P3)+P4)/6;
		RR = RR+(Q1+2*(Q2+Q3)+Q4)/6;
		PP = PP+(R1+2*(R2+R3)+R4)/6;
		/*----------------------------------------*/
		YY = YY+((XX-XA)*(XX-XA)+(ZZ-ZA)*(ZZ-ZA))/12713532; /* CORREÇÃO DEVIDA À CURVATURA DA TERRA */
		G = G-2*G*(YY-YA)/6356766;

		/* ATUALIZAÇÃO DA GRAVIDADE */
		fprintf (arqsaida,"%lf\t%lf\t%lf\t%lf\t%lf\n",TT,XX,YY,ZZ,alfae);
	}

	fclose(arqsaida);
	return (0);
}


double InterpCd (double Cd[2][25], double X)
{
	int i;
	double DEN, A, B, Y;
	i = 0;
	while (Cd[0][i] <= X)  i = i+1;

	DEN = Cd[0][i]-Cd[0][i-1];
	A = (Cd[1][i]-Cd[1][i-1])/DEN;
	B = (Cd[0][i]*Cd[1][i-1]-Cd[0][i-1]*Cd[1][i])/DEN;
	Y = A*X+B;
	return (Y);
}


double InterpCna (double Cna[2][22], double X)
{
	int i;
	double DEN, A, B, Y;
	i = 0;
	while (Cna[0][i] <= X)
	i = i+1;
	DEN = Cna[0][i]-Cna[0][i-1];
	A = (Cna[1][i]-Cna[1][i-1])/DEN;
	B = (Cna[0][i]*Cna[1][i-1]-Cna[0][i-1]*Cna[1][i])/DEN;
	Y = A*X+B;

	return (Y);
}


double InterpCnpa (double Cnpa[2][16], double X)
{
	int i;
	double DEN, A, B, Y;
	i = 0;
	while (Cnpa[0][i] <= X) i = i+1;
	DEN = Cnpa[0][i]-Cnpa[0][i-1];
	A = (Cnpa[1][i]-Cnpa[1][i-1])/DEN;
	B = (Cnpa[0][i]*Cnpa[1][i-1]-Cnpa[0][i-1]*Cnpa[1][i])/DEN;
	Y = A*X+B;
	return (Y);
}


double InterpClp (double Clp[2][14], double X)
{
	int i;
	double DEN, A, B, Y;
	i = 0;
	while (Clp[0][i] <= X) i = i+1;

	DEN = Clp[0][i]-Clp[0][i-1];
	A = (Clp[1][i]-Clp[1][i-1])/DEN;
	B = (Clp[0][i]*Clp[1][i-1]-Clp[0][i-1]*Clp[1][i])/DEN;
	Y = A*X+B;
	return (Y);
}

double InterpCma (double Cma[2][25], double X)
{
	int i;
	double DEN, A, B, Y;
	i = 0;
	while (Cma[0][i] <= X)	i = i+1;
	DEN = Cma[0][i]-Cma[0][i-1];
	A = (Cma[1][i]-Cma[1][i-1])/DEN;
	B = (Cma[0][i]*Cma[1][i-1]-Cma[0][i-1]*Cma[1][i])/DEN;
	Y = A*X+B;
	return (Y);
}

double ka (double Ro, double S, double M)
{
	double KA;
	KA = Ro*S*0.5/M;
	return (KA);
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

double XFUN (double UU,double VV,double WW,double PP,double KA,double KB,double dgir,double CD,double
	CLA,double CMA,double CNPA,double G,double OM,double L,double AZ)
	{
	return(-KA*CD*sqrt(UU*UU+VV*VV+WW*WW)*UU+KB*CLA/CMA/(UU*UU+VV*VV+WW*WW)*PP*(-
	G*WW)+KB*CNPA/CMA*dgir*PP*PP/(UU*UU+VV*VV+WW*WW)/(UU*UU+VV*VV+WW*WW)*(G*VV*UU)+2*OM*(-
	VV*cos(L)*sin(AZ)-WW*sin(L)));
}

double YFUN (double UU,double VV,double WW,double PP,double KA,double KB,double dgir,double CD,double
CLA,double CMA,double CNPA,double G,double OM,double L,double AZ)
{
	return(-
	KA*CD*sqrt(UU*UU+VV*VV+WW*WW)*VV+KB*CNPA/CMA*dgir*PP*PP/(UU*UU+VV*VV+WW*WW)/(UU*UU+VV*VV+
	WW*WW)*(-G*(UU*UU+WW*WW))-G+2*OM*(UU*cos(L)*sin(AZ)+WW*cos(L)*cos(AZ)));
}

double ZFUN (double UU,double VV,double WW,double PP,double KA,double KB,double dgir,double CD,double
CLA,double CMA,double CNPA,double G,double OM,double L,double AZ)
{
	return(-
	KA*CD*sqrt(UU*UU+VV*VV+WW*WW)*WW+KB*CLA/CMA/(UU*UU+VV*VV+WW*WW)*PP*(G*UU)+KB*CNPA/CMA*dgir*PP*PP/(UU*UU+VV*VV+WW*WW)/(UU*UU+VV*VV+WW*WW)*(G*VV*WW)+2*OM*(UU*sin(L)-VV*cos(L)*cos(AZ)));
}

double PFUN (double UU,double VV,double WW,double PP,double KA,double KB,double dgir,double M,double
IX,double CLP)
{
	return(KA*M/IX*dgir*dgir*sqrt(UU*UU+VV*VV+WW*WW)*PP*CLP);
}

double RAD(double MIL)
{
	return (MIL*M_PI/3200);
}