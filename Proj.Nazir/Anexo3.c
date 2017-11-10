//#include <vcl\condefs.h>
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
	double InterpCmq (double Cmq[2][14], double X);
	double InterpCnp (double Cnp[2][30], double X);
	double Vtil (double Vx, double Vy, double Vz, double Wx, double Wy, double Wz);
	double Ro (double Altitude);
	double VSom (double Temperatura, double Altura);
	double Mach (double Temperatura, double Altura, double VTIL);
	double XFUN (double UU,double VV,double WW,double H1,double H2,double H3,double X1,double X2,double
	X3,double CO1,double DGIR,double PP,double G,double CD,double CLA,double CNPA,double CNQ,double CNA);
	
	double YFUN (double UU,double VV,double WW,double H1,double H2,double H3,double X1,double X2,double
	X3,double CO1,double DGIR,double PP,double G,double CD,double CLA,double CNPA,double CNQ,double CNA);
	
	double ZFUN (double UU,double VV,double WW,double H1,double H2,double H3,double X1,double X2,double
	X3,double CO1,double DGIR,double PP,double G,double CD,double CLA,double CNPA,double CNQ,double CNA);
	
	double H1FUN (double UU,double VV,double WW,double H1,double H2,double H3,double X1,double X2,double
	X3,double CO2,double DGIR,double Ix,double Iy,double PP,double CLP,double CMA,double CMPA,double CMQ,double
	CMG);
	
	double H2FUN (double UU,double VV,double WW,double H1,double H2,double H3,double X1,double X2,double
X3,double CO2,double DGIR,double Ix,double Iy,double PP,double CLP,double CMA,double CMPA,double CMQ,double
CMG);
	
	double H3FUN (double UU,double VV,double WW,double H1,double H2,double H3,double X1,double X2,double
X3,double CO2,double DGIR,double Ix,double Iy,double PP,double CLP,double CMA,double CMPA,double CMQ,double
CMG);
	double X1FUN (double H1,double H2,double H3,double X1,double X2,double X3);
	double X2FUN (double H1,double H2,double H3,double X1,double X2,double X3);
	double X3FUN (double H1,double H2,double H3,double X1,double X2,double X3);
	double RAD (double MIL);
	double TT,XX,YY,ZZ,UU,VV,WW,H1,H2,H3,X1,X2,X3,Y1,Y2,Y3,Z1,Z2,Z3,Q,H,XA,YA,ZA;
	double K1,L1,M1,N1,O1,P1,Q1,R1,S1,T1,U1,V1;
	double K2,L2,M2,N2,O2,P2,Q2,R2,S2,T2,U2,V2;
	double K3,L3,M3,N3,O3,P3,Q3,R3,S3,T3,U3,V3;
	double K4,L4,M4,N4,O4,P4,Q4,R4,S4,T4,U4,V4;
	double M, S, Ix, Iy, Wx, Wy, Wz, V0, FI, TETA, Alfa, Beta, PP, P0, DGIR, X0, Y0, Z0,G;
	double Vx, Vy, Vz, MACH, TempFahr, CO1, CO2, ATQ, FLECHA;
	double Wx0a2000,Wy0a2000,Wz0a2000,Wx2000a4000,Wy2000a4000,Wz2000a4000;
	double Wx4000a6000,Wy4000a6000,Wz4000a6000,Wx6000a8000,Wy6000a8000,Wz6000a8000;
	double CD,CLA,CNPA,CNQ,CNA,CLP,CMA,CMPA,CMQ,CMG;

	FILE *arqsaida;		
	arqsaida=fopen("saida3.txt","w");

	/*--------DADOS DA MUNIÇÃO-----------*/

	M = 14.970;
	S = M_PI*0.10485*0.10485/4;
	Ix = 0.023303;
	Iy = 0.22563;
	DGIR = 0.10485;

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
	
	double Cmqtab[2][14] = {0,0.8,0.85,0.875,0.9,0.925,0.95,0.975,1,1.025,1.05,1.1,1.2,1000,
-7.3,-7.3,-8,-8.4,-8.7,-9.1,-9.5,-10.2,-12,-13,-14,-15,-17,-17};

	double CnpAT1[2][30] =
{0.01,0.4,0.6,0.7,0.75,0.8,0.85,0.875,0.9,0.925,0.95,0.975,1,1.025,1.05,1.1,1.2,1.35,1.5,1.75,2,2.25,2.5,3,3.5,4,4.5,5,6,8,
-0.0175,-0.0175,-0.0175,-0.0175,-0.0175,-0.0175,-0.0159,-0.0150,-0.0141,-0.0133,-0.0085,-
0.0042,0.0024,0.0050,0.0057,0.0061,0.0077,0.0077,0.0078,0.0078,0.0079,0.0080,0.0080,0.0084,0.0084,0.0084,0.0084,
0.0084,0.0084,0.0084};
	
	double CnpAT2[2][30] =
{0.01,0.4,0.6,0.7,0.75,0.8,0.85,0.875,0.9,0.925,0.95,0.975,1,1.025,1.05,1.1,1.2,1.35,1.5,1.75,2,2.25,2.5,3,3.5,4,4.5,5,6,8,
-0.0248,-0.0248,-0.0248,-0.0248,-0.0248,-0.0248,-0.0215,-0.0197,-0.0180,-0.0163,-0.0084,-
0.0013,0.0086,0.0124,0.0131,0.0135,0.0158,0.0158,0.0158,0.0160,0.0161,0.0161,0.0161,0.0133,0.0133,0.0133,0.0133,
0.0133,0.0133,0.0133};
	
	double CnpAT3[2][30] =
{0.01,0.4,0.6,0.7,0.75,0.8,0.85,0.875,0.9,0.925,0.95,0.975,1,1.025,1.05,1.1,1.2,1.35,1.5,1.75,2,2.25,2.5,3,3.5,4,4.5,5,6,8,
-0.0168,-0.0168,-0.0168,-0.0168,-0.0168,-0.0168,-0.0116,-0.0089,-0.0063,-
0.0037,0.0043,0.0123,0.0205,0.0230,0.0228,0.0229,0.0243,0.0243,0.0243,0.0244,0.0245,0.0246,0.0246,0.0124,0.0124,
0.0124,0.0124,0.0124,0.0124,0.0124};
	
	double CnpAT4[2][30] =
{0.01,0.4,0.6,0.7,0.75,0.8,0.85,0.875,0.9,0.925,0.95,0.975,1,1.025,1.05,1.1,1.2,1.35,1.5,1.75,2,2.25,2.5,3,3.5,4,4.5,5,6,8,
-0.0061,-0.0061,-0.0061,-0.0061,-0.0061,-
0.0061,0.0009,0.0044,0.0079,0.0114,0.0184,0.0273,0.0328,0.0334,0.0326,0.0323,0.0327,0.0327,0.0327,0.0328,0.0329,
0.0329,0.0329,0.0082,0.0082,0.0082,0.0082,0.0082,0.0082,0.0082};

	double CnpAT5[2][30] =
{0.01,0.4,0.6,0.7,0.75,0.8,0.85,0.875,0.9,0.925,0.95,0.975,1,1.025,1.05,1.1,1.2,1.35,1.5,1.75,2,2.25,2.5,3,3.5,4,4.5,5,6,8,
0.0128,0.0128,0.0128,0.0128,0.0128,0.0128,0.0215,0.0258,0.0302,0.0346,0.0389,0.0477,0.0478,0.0452,0.0435,0.0427,
0.0412,0.0413,0.0413,0.0413,0.0413,0.0413,0.0413,-0.0003,-0.0003,-0.0003,-0.0003,-0.0003,-0.0003,-0.0003};

	double CnpAT7v5[2][30] =
{0.01,0.4,0.6,0.7,0.75,0.8,0.85,0.875,0.9,0.925,0.95,0.975,1,1.025,1.05,1.1,1.2,1.35,1.5,1.75,2,2.25,2.5,3,3.5,4,4.5,5,6,8,
0.0605,0.0605,0.0605,0.0638,0.0654,0.0670,0.0806,0.0874,0.0942,0.1079,0.1216,0.1080,0.0899,0.0811,0.0727,0.0712,
0.0682,0.0682,0.0682,0.0682,0.0682,0.0682,0.0682,-0.0002,-0.0002,-0.0002,-0.0002,-0.0002,-0.0002,-0.0002};
	
	double CnpAT10[2][30] =
{0.01,0.4,0.6,0.7,0.75,0.8,0.85,0.875,0.9,0.925,0.95,0.975,1,1.025,1.05,1.1,1.2,1.35,1.5,1.75,2,2.25,2.5,3,3.5,4,4.5,5,6,8,
0.1082,0.1082,0.1082,0.1147,0.1180,0.1212,0.1397,0.1490,0.1582,0.1813,0.2044,0.1682,0.1320,0.1170,0.1019,0.0997,
0.0952,0.0952,0.0952,0.0952,0.0952,0.0952,0.0952,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000};
	
	double CnpAT15[2][30] =
{0.01,0.4,0.6,0.7,0.75,0.8,0.85,0.875,0.9,0.925,0.95,0.975,1,1.025,1.05,1.1,1.2,1.35,1.5,1.75,2,2.25,2.5,3,3.5,4,4.5,5,6,8,
0.1532,0.1532,0.1532,0.1624,0.1671,0.1717,0.1979,0.2110,0.2241,0.2568,0.2895,0.2382,0.1870,0.1656,0.1443,0.1412,
0.1348,0.1348,0.1348,0.1348,0.1348,0.1348,0.1348,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000};
	
	double CnpAT20[2][30] =
{0.01,0.4,0.6,0.7,0.75,0.8,0.85,0.875,0.9,0.925,0.95,0.975,1,1.025,1.05,1.1,1.2,1.35,1.5,1.75,2,2.25,2.5,3,3.5,4,4.5,5,6,8,
0.1918,0.1918,0.1918,0.2034,0.2091,0.2149,0.2477,0.2641,0.2805,0.3214,0.3624,0.2982,0.2341,0.2074,0.1807,0.1767,
0.1688,0.1688,0.1688,0.1688,0.1688,0.1688,0.1688,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000};
	
	double CnpAT30[2][30] =
{0.01,0.4,0.6,0.7,0.75,0.8,0.85,0.875,0.9,0.925,0.95,0.975,1,1.025,1.05,1.1,1.2,1.35,1.5,1.75,2,2.25,2.5,3,3.5,4,4.5,5,6,8,
0.2524,0.2524,0.2524,0.2676,0.2752,0.2827,0.3259,0.3475,0.3691,0.4229,0.4768,0.3924,0.3080,0.2728,0.2377,0.2325,
0.2221,0.2221,0.2221,0.2221,0.2221,0.2221,0.2221,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000};
	
	double CnpAT60[2][30] =
{0.01,0.4,0.6,0.7,0.75,0.8,0.85,0.875,0.9,0.925,0.95,0.975,1,1.025,1.05,1.1,1.2,1.35,1.5,1.75,2,2.25,2.5,3,3.5,4,4.5,5,6,8,
0.3400,0.3400,0.3400,0.3605,0.3707,0.3809,0.4390,0.4681,0.4972,0.5697,0.6423,0.5286,0.4149,0.3676,0.3203,0.3132,
0.2991,0.2991,0.2991,0.2991,0.2991,0.2991,0.2991,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000};
	
	double CnpAT90[2][30] =
{0.01,0.4,0.6,0.7,0.75,0.8,0.85,0.875,0.9,0.925,0.95,0.975,1,1.025,1.05,1.1,1.2,1.35,1.5,1.75,2,2.25,2.5,3,3.5,4,4.5,5,6,8,
0.2804,0.2804,0.2804,0.2973,0.3057,0.3142,0.3621,0.3861,0.4101,0.4699,0.5297,0.4360,0.3422,0.3032,0.2642,0.2584,
0.2467,0.2467,0.2467,0.2467,0.2467,0.2467,0.2467,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000,0.0000};


/*----------------------------------*/
/*-------DADOS METEOROLÓGICOS-------*/
	Wx0a2000 = 0; Wx2000a4000 = 0; Wx4000a6000 = 0; Wx6000a8000 = 0;
	Wy0a2000 = 0; Wy2000a4000 = 0; Wy4000a6000 = 0; Wy6000a8000 = 0;
	Wz0a2000 = 0; Wz2000a4000 = 0; Wz4000a6000 = 0; Wz6000a8000 = 0;
	G = 9.81;
	TempFahr = 59;

	/*----------------------------------*/
	/*---------DADOS DO TIRO------------*/
	V0 = 464.8;
	P0 = 1545;
	printf ("TRAJETOGRAFO PARA 105mm M1\n\n");
	printf ("Insira o angulo de elevacao: ");
	scanf("%lf",&FI);
	printf ("Insira o angulo de deriva: ");
	scanf("%lf",&TETA);
	X0 = Y0 = Z0 = 0;
	Alfa = 0;
	Beta = 0;	
	/*----------------------------------*/
	H = 0.01; 
	/* INCREMENTO DESEJADO DE TEMPO */
	/*-DEFINIÇÃO DAS CONDIÇÒES INICIAIS-*/
	
	Vx = V0*cos(RAD(FI))*cos(RAD(TETA));
	Vy = V0*sin(RAD(FI))*cos(RAD(TETA));
	Vz = V0*sin(RAD(TETA));
	Q = pow(sin(RAD(TETA+Beta)),2)+pow(cos(RAD(TETA+Beta)),2)*pow(cos(RAD(FI+Alfa)),2);

	X1 = cos(RAD(FI+Alfa))*cos(RAD(TETA+Beta));
	X2 = sin(RAD(FI+Alfa))*cos(RAD(TETA+Beta));
	X3 = sin(RAD(TETA+Beta));
	Y1 = 1/sqrt(Q)*(-pow(cos(RAD(TETA+Beta)),2)*sin(RAD(FI+Alfa))*cos(RAD(FI+Alfa)));
	Y2 = 1/sqrt(Q)*(pow(cos(RAD(TETA+Beta)),2)*sin(RAD(FI+Alfa))+pow(sin(RAD(TETA+Beta)),2));
	Y3 = 1/sqrt(Q)*(-sin(RAD(TETA+Beta))*cos(RAD(TETA+Beta))*sin(RAD(FI+Alfa)));
	Z1 = 1/sqrt(Q)*(-sin(RAD(TETA+Beta)));
	Z2 = 0;
	Z3 = 1/sqrt(Q)*cos(RAD(TETA+Beta))*cos(RAD(FI+Alfa));
	H1 = Ix*P0/Iy*X1;
	H2 = Ix*P0/Iy*X2;
	H3 = Ix*P0/Iy*X3;
	TT = 0;
	XX = X0;
	YY = Y0;
	ZZ = Z0;
	UU = Vx-Wx;
	VV = Vy-Wy;
	WW = Vz-Wz;
	
	/*----------------------------------*/
	while (YY>=0) { /* CONDIÇÃO DE TÉRMINO DE TRAJETÓRIA */
		if ((0<=YY) && (YY<2000)) {Wx = Wx0a2000; Wy = Wy0a2000; Wz = Wz0a2000;}
		if ((2000<=YY) && (YY<4000)) {Wx = Wx2000a4000; Wy = Wy2000a4000; Wz = Wz2000a4000;}
		if ((4000<=YY) && (YY<6000)) {Wx = Wx4000a6000; Wy = Wy4000a6000; Wz = Wz4000a6000;}
		if ((6000<=YY) && (YY<8000)) {Wx = Wx6000a8000; Wy = Wy6000a8000; Wz = Wz6000a8000;}
		XA = XX;
		YA = YY;
		ZA = ZZ;
		MACH = Mach(TempFahr,YY,sqrt(UU*UU+VV*VV+WW*WW));
		CD = InterpCd(Cdtab,MACH);
		CLA = InterpCna(Cnatab,MACH)*(UU*X1+VV*X2+WW*X3)/sqrt((UU*UU+VV*VV+WW*WW))+CD;
		CMA = InterpCma(Cmatab,MACH);
		CNPA = -InterpCnpa(Cnpatab,MACH);
		CNQ = 0;
		CNA = 0;
		CLP = InterpClp(Clptab,MACH);
		CMQ = InterpCmq(Cmqtab,MACH);
		CMG = 0;
		ATQ = acos((UU*X1+VV*X2+WW*X3)/sqrt((UU*UU+VV*VV+WW*WW)))*180/M_PI;
		if ((0<=ATQ) && (ATQ<1)) CMPA = (InterpCnp(CnpAT1,MACH)-0)*(ATQ-0)/(1-0)+0;
		if ((1<=ATQ) && (ATQ<2)) CMPA = (InterpCnp(CnpAT2,MACH)-InterpCnp(CnpAT1,MACH))*(ATQ-1)/(2-
		1)+InterpCnp(CnpAT1,MACH);
		if ((2<=ATQ) && (ATQ<3)) CMPA = (InterpCnp(CnpAT3,MACH)-InterpCnp(CnpAT2,MACH))*(ATQ-2)/(3-
		2)+InterpCnp(CnpAT2,MACH);
		if ((3<=ATQ) && (ATQ<4)) CMPA = (InterpCnp(CnpAT4,MACH)-InterpCnp(CnpAT3,MACH))*(ATQ-3)/(4-
		3)+InterpCnp(CnpAT3,MACH);
		if ((4<=ATQ) && (ATQ<5)) CMPA = (InterpCnp(CnpAT5,MACH)-InterpCnp(CnpAT4,MACH))*(ATQ-4)/(5-
		4)+InterpCnp(CnpAT4,MACH);
		if ((5<=ATQ) && (ATQ<7.5)) CMPA = (InterpCnp(CnpAT7v5,MACH)-InterpCnp(CnpAT5,MACH))*(ATQ-5)/(7.5-
		5)+InterpCnp(CnpAT5,MACH);
		if ((7.5<=ATQ) && (ATQ<10)) CMPA = (InterpCnp(CnpAT10,MACH)-InterpCnp(CnpAT7v5,MACH))*(ATQ-7.5)/(10-
		7.5)+InterpCnp(CnpAT7v5,MACH);
		if ((10<=ATQ) && (ATQ<15)) CMPA = (InterpCnp(CnpAT15,MACH)-InterpCnp(CnpAT10,MACH))*(ATQ-10)/(15-
		10)+InterpCnp(CnpAT10,MACH);
		if ((15<=ATQ) && (ATQ<20)) CMPA = (InterpCnp(CnpAT20,MACH)-InterpCnp(CnpAT15,MACH))*(ATQ-15)/(20-
		15)+InterpCnp(CnpAT15,MACH);
		if ((20<=ATQ) && (ATQ<30)) CMPA = (InterpCnp(CnpAT30,MACH)-InterpCnp(CnpAT20,MACH))*(ATQ-20)/(30-
		20)+InterpCnp(CnpAT20,MACH);
		if ((30<=ATQ) && (ATQ<60)) CMPA = (InterpCnp(CnpAT60,MACH)-InterpCnp(CnpAT30,MACH))*(ATQ-30)/(60-
		30)+InterpCnp(CnpAT30,MACH);
		if ((60<=ATQ) && (ATQ<90)) CMPA = (InterpCnp(CnpAT90,MACH)-InterpCnp(CnpAT60,MACH))*(ATQ-60)/(90-
		60)+InterpCnp(CnpAT60,MACH);
		CO1 = Ro(YY)*S/2/M;
		CO2 = Ro(YY)*S*DGIR/2/Iy;
		PP = Iy/Ix*(H1*X1+H2*X2+H3*X3);
		
		/* -----BLOCO RUNGE-KUTTA 4a. ORDEM ------*/
		K1 = H*UU;
		L1 = H*XFUN(UU,VV,WW,H1,H2,H3,X1,X2,X3,CO1,DGIR,PP,G,CD,CLA,CNPA,CNQ,CNA);
		M1 = H*VV;
		N1 = H*YFUN(UU,VV,WW,H1,H2,H3,X1,X2,X3,CO1,DGIR,PP,G,CD,CLA,CNPA,CNQ,CNA);
		O1 = H*WW;
		P1 = H*ZFUN(UU,VV,WW,H1,H2,H3,X1,X2,X3,CO1,DGIR,PP,G,CD,CLA,CNPA,CNQ,CNA);
		Q1 = H*H1FUN(UU,VV,WW,H1,H2,H3,X1,X2,X3,CO2,DGIR,Ix,Iy,PP,CLP,CMA,CMPA,CMQ,CMG);
		R1 = H*H2FUN(UU,VV,WW,H1,H2,H3,X1,X2,X3,CO2,DGIR,Ix,Iy,PP,CLP,CMA,CMPA,CMQ,CMG);
		S1 = H*H3FUN(UU,VV,WW,H1,H2,H3,X1,X2,X3,CO2,DGIR,Ix,Iy,PP,CLP,CMA,CMPA,CMQ,CMG);
		T1 = H*X1FUN(H1,H2,H3,X1,X2,X3);
		U1 = H*X2FUN(H1,H2,H3,X1,X2,X3);
		V1 = H*X3FUN(H1,H2,H3,X1,X2,X3);
		K2 = H*(UU+L1/2);
		L2 =
		H*XFUN(UU+L1/2,VV+N1/2,WW+P1/2,H1+Q1/2,H2+R1/2,H3+S1/2,X1+T1/2,X2+U1/2,X3+V1/2,CO1,DGIR,PP,G,CD,CLA,CNPA,CNQ,CNA);
		M2 = H*(VV+N1/2);
		N2 =
		H*YFUN(UU+L1/2,VV+N1/2,WW+P1/2,H1+Q1/2,H2+R1/2,H3+S1/2,X1+T1/2,X2+U1/2,X3+V1/2,CO1,DGIR,PP,G,CD,CLA,CNPA,CNQ,CNA);
		O2 = H*(WW+P1/2);
		P2 =
		H*ZFUN(UU+L1/2,VV+N1/2,WW+P1/2,H1+Q1/2,H2+R1/2,H3+S1/2,X1+T1/2,X2+U1/2,X3+V1/2,CO1,DGIR,PP,G,CD,CLA,CNPA,CNQ,CNA);
		Q2 =
		H*H1FUN(UU+L1/2,VV+N1/2,WW+P1/2,H1+Q1/2,H2+R1/2,H3+S1/2,X1+T1/2,X2+U1/2,X3+V1/2,CO2,DGIR,Ix,Iy,PP,CLP,CMA,CMPA,CMQ,CMG);
		R2 =
		H*H2FUN(UU+L1/2,VV+N1/2,WW+P1/2,H1+Q1/2,H2+R1/2,H3+S1/2,X1+T1/2,X2+U1/2,X3+V1/2,CO2,DGIR,Ix,Iy,PP,CLP,CMA,CMPA,CMQ,CMG);
		S2 =
		H*H3FUN(UU+L1/2,VV+N1/2,WW+P1/2,H1+Q1/2,H2+R1/2,H3+S1/2,X1+T1/2,X2+U1/2,X3+V1/2,CO2,DGIR,Ix,Iy,PP,CLP,CMA,CMPA,CMQ,CMG);
		T2 = H*X1FUN(H1+Q1/2,H2+R1/2,H3+S1/2,X1+T1/2,X2+U1/2,X3+V1/2);
		U2 = H*X2FUN(H1+Q1/2,H2+R1/2,H3+S1/2,X1+T1/2,X2+U1/2,X3+V1/2);
		V2 = H*X3FUN(H1+Q1/2,H2+R1/2,H3+S1/2,X1+T1/2,X2+U1/2,X3+V1/2);
		K3 = H*(UU+L2/2);
		L3 =
		H*XFUN(UU+L2/2,VV+N2/2,WW+P2/2,H1+Q2/2,H2+R2/2,H3+S2/2,X1+T2/2,X2+U2/2,X3+V2/2,CO1,DGIR,PP,G,CD,CLA,CNPA,CNQ,CNA);
		M3 = H*(VV+N2/2);
		N3 =
		H*YFUN(UU+L2/2,VV+N2/2,WW+P2/2,H1+Q2/2,H2+R2/2,H3+S2/2,X1+T2/2,X2+U2/2,X3+V2/2,CO1,DGIR,PP,G,CD,CLA,CNPA,CNQ,CNA);
		O3 = H*(WW+P2/2);
		P3 =
		H*ZFUN(UU+L2/2,VV+N2/2,WW+P2/2,H1+Q2/2,H2+R2/2,H3+S2/2,X1+T2/2,X2+U2/2,X3+V2/2,CO1,DGIR,PP,G,CD,CLA,CNPA,CNQ,CNA);
		Q3 =
		H*H1FUN(UU+L2/2,VV+N2/2,WW+P2/2,H1+Q2/2,H2+R2/2,H3+S2/2,X1+T2/2,X2+U2/2,X3+V2/2,CO2,DGIR,Ix,Iy,PP,CLP,CMA,CMPA,CMQ,CMG);
		R3 =
		H*H2FUN(UU+L2/2,VV+N2/2,WW+P2/2,H1+Q2/2,H2+R2/2,H3+S2/2,X1+T2/2,X2+U2/2,X3+V2/2,CO2,DGIR,Ix,Iy,PP,CLP,CMA,CMPA,CMQ,CMG);
		S3 =
		H*H3FUN(UU+L2/2,VV+N2/2,WW+P2/2,H1+Q2/2,H2+R2/2,H3+S2/2,X1+T2/2,X2+U2/2,X3+V2/2,CO2,DGIR,Ix,Iy,PP,CLP,CMA,CMPA,CMQ,CMG);
		T3 = H*X1FUN(H1+Q2/2,H2+R2/2,H3+S2/2,X1+T2/2,X2+U2/2,X3+V2/2);
		U3 = H*X2FUN(H1+Q2/2,H2+R2/2,H3+S2/2,X1+T2/2,X2+U2/2,X3+V2/2);
		V3 = H*X3FUN(H1+Q2/2,H2+R2/2,H3+S2/2,X1+T2/2,X2+U2/2,X3+V2/2);
		K4 = H*(UU+L3);
		L4 =
		H*XFUN(UU+L3,VV+N3,WW+P3,H1+Q3,H2+R3,H3+S3,X1+T3,X2+U3,X3+V3,CO1,DGIR,PP,G,CD,CLA,CNPA,CNQ,CNA);
		M4 = H*(VV+N3);
		N4 =
		H*YFUN(UU+L3,VV+N3,WW+P3,H1+Q3,H2+R3,H3+S3,X1+T3,X2+U3,X3+V3,CO1,DGIR,PP,G,CD,CLA,CNPA,CNQ,CNA);
		O4 = H*(WW+P3);
		P4 =
		H*ZFUN(UU+L3,VV+N3,WW+P3,H1+Q3,H2+R3,H3+S3,X1+T3,X2+U3,X3+V3,CO1,DGIR,PP,G,CD,CLA,CNPA,CNQ,CNA);
		Q4 =
		H*H1FUN(UU+L3,VV+N3,WW+P3,H1+Q3,H2+R3,H3+S3,X1+T3,X2+U3,X3+V3,CO2,DGIR,Ix,Iy,PP,CLP,CMA,CMPA,CMQ,CMG);
		R4 =
		H*H2FUN(UU+L3,VV+N3,WW+P3,H1+Q3,H2+R3,H3+S3,X1+T3,X2+U3,X3+V3,CO2,DGIR,Ix,Iy,PP,CLP,CMA,CMPA,CMQ,CMG);
		S4 =
		H*H3FUN(UU+L3,VV+N3,WW+P3,H1+Q3,H2+R3,H3+S3,X1+T3,X2+U3,X3+V3,CO2,DGIR,Ix,Iy,PP,CLP,CMA,CMPA,CMQ,CMG);
		T4 = H*X1FUN(H1+Q3,H2+R3,H3+S3,X1+T3,X2+U3,X3+V3);
		U4 = H*X2FUN(H1+Q3,H2+R3,H3+S3,X1+T3,X2+U3,X3+V3);
		V4 = H*X3FUN(H1+Q3,H2+R3,H3+S3,X1+T3,X2+U3,X3+V3);
		TT = TT+H;
		XX = XX+(K1+2*(K2+K3)+K4)/6+Wx*H; /* CORREÇÃO DEVIDA AO VENTO */
		UU = UU+(L1+2*(L2+L3)+L4)/6;
		YY = YY+(M1+2*(M2+M3)+M4)/6+Wy*H; /* CORREÇÃO DEVIDA AO VENTO */
		if (((M1+2*(M2+M3)+M4)/6)>0) FLECHA = YY;
		VV = VV+(N1+2*(N2+N3)+N4)/6;
		ZZ = ZZ+(O1+2*(O2+O3)+O4)/6+Wz*H; /* CORREÇÃO DEVIDA AO VENTO */
		WW = WW+(P1+2*(P2+P3)+P4)/6;
		H1 = H1+(Q1+2*(Q2+Q3)+Q4)/6;
		H2 = H2+(R1+2*(R2+R3)+R4)/6;
		H3 = H3+(S1+2*(S2+S3)+S4)/6;
		X1 = X1+(T1+2*(T2+T3)+T4)/6;
		X2 = X2+(U1+2*(U2+U3)+U4)/6;
		X3 = X3+(V1+2*(V2+V3)+V4)/6;
		/*----------------------------------------*/
		YY = YY+((XX-XA)*(XX-XA)+(ZZ-ZA)*(ZZ-ZA))/12713532; /* CORREÇÃO DEVIDA À CURVATURA DA TERRA */
		G = G-2*G*(YY-YA)/6356766;
		/* ATUALIZAÇÃO DA GRAVIDADE */
		fprintf (arqsaida,"%lf\t%lf\t%lf\t%lf\t%lf\n",TT,XX,YY,ZZ,FLECHA);
		/*fprintf (arqsaida,"%lf\t%lf\t%lf\t%lf\t%lf\n",TT,XX,YY,(X1-
		UU/sqrt(UU*UU+VV*VV+WW*WW))*WW*UU/(UU*UU+VV*VV+WW*WW)+(X2-
		VV/sqrt(UU*UU+VV*VV+WW*WW))*WW*VV/(UU*UU+VV*VV+WW*WW)+(X3-WW/sqrt(UU*UU+VV*VV+WW*WW))*(-
		UU*UU-VV*VV)/(UU*UU+VV*VV+WW*WW),(X1-
		UU/sqrt(UU*UU+VV*VV+WW*WW))*VV/sqrt(UU*UU+VV*VV+WW*WW)-(X2-
		VV/sqrt(UU*UU+VV*VV+WW*WW))*UU/sqrt(UU*UU+VV*VV+WW*WW)); */
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

double InterpCna (double Cna[2][22], double X)
{
	int i;
	double DEN, A, B, Y;
	i = 0;
	while (Cna[0][i] <= X)	i = i+1;
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
	while (Cnpa[0][i] <= X)
	i = i+1;
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
	while (Clp[0][i] <= X)
	i = i+1;
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
	while (Cma[0][i] <= X)
	i = i+1;
	DEN = Cma[0][i]-Cma[0][i-1];
	A = (Cma[1][i]-Cma[1][i-1])/DEN;
	B = (Cma[0][i]*Cma[1][i-1]-Cma[0][i-1]*Cma[1][i])/DEN;
	Y = A*X+B;
	return (Y);
}

double InterpCmq (double Cmq[2][14], double X)
{
	int i;
	double DEN, A, B, Y;
	i = 0;
	while (Cmq[0][i] <= X) i = i+1;
	DEN = Cmq[0][i]-Cmq[0][i-1];
	A = (Cmq[1][i]-Cmq[1][i-1])/DEN;
	B = (Cmq[0][i]*Cmq[1][i-1]-Cmq[0][i-1]*Cmq[1][i])/DEN;
	Y = A*X+B;
	return (Y);
}

double InterpCnp (double Cnp[2][30], double X)
{
	int i;
	double DEN, A, B, Y;
	i = 0;
	while (Cnp[0][i] <= X) i = i+1;
	DEN = Cnp[0][i]-Cnp[0][i-1];
	A = (Cnp[1][i]-Cnp[1][i-1])/DEN;
	B = (Cnp[0][i]*Cnp[1][i-1]-Cnp[0][i-1]*Cnp[1][i])/DEN;
	Y = A*X+B;
	return (Y);
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
	RO = 0.0765*exp(-Altitude/(12*.0254)*h);
	return(16.02*RO);//18463374*RO);
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

double XFUN (double UU,double VV,double WW,double H1,double H2,double H3,double X1,double X2,double
X3,double CO1,double DGIR,double PP,double G,double CD,double CLA,double CNPA,double CNQ,double CNA)
{
	return(-CD*CO1*sqrt(UU*UU+VV*VV+WW*WW)*UU+CLA*CO1*((UU*UU+VV*VV+WW*WW)*X1-
UU*(UU*X1+VV*X2+WW*X3))-CNPA*CO1*DGIR*PP*(X2*WW-
X3*VV)+(CNQ+CNA)*CO1*DGIR*sqrt(UU*UU+VV*VV+WW*WW)*(H2*X3-H3*X2));
}

double YFUN (double UU,double VV,double WW,double H1,double H2,double H3,double X1,double X2,double
X3,double CO1,double DGIR,double PP,double G,double CD,double CLA,double CNPA,double CNQ,double CNA)
{
	return(-CD*CO1*sqrt(UU*UU+VV*VV+WW*WW)*VV+CLA*CO1*((UU*UU+VV*VV+WW*WW)*X2-
	VV*(UU*X1+VV*X2+WW*X3))-CNPA*CO1*DGIR*PP*(X3*UU-
	X1*WW)+(CNQ+CNA)*CO1*DGIR*sqrt(UU*UU+VV*VV+WW*WW)*(H3*X1-H1*X3)-G);
}

double ZFUN (double UU,double VV,double WW,double H1,double H2,double H3,double X1,double X2,double
X3,double CO1,double DGIR,double PP,double G,double CD,double CLA,double CNPA,double CNQ,double CNA)
{
	return(-CD*CO1*sqrt(UU*UU+VV*VV+WW*WW)*WW+CLA*CO1*((UU*UU+VV*VV+WW*WW)*X3-
	WW*(UU*X1+VV*X2+WW*X3))-CNPA*CO1*DGIR*PP*(X1*VV-
	X2*UU)+(CNQ+CNA)*CO1*DGIR*sqrt(UU*UU+VV*VV+WW*WW)*(H1*X2-H2*X1));
}

double H1FUN (double UU,double VV,double WW,double H1,double H2,double H3,double X1,double X2,double
X3,double CO2,double DGIR,double Ix,double Iy,double PP,double CLP,double CMA,double CMPA,double CMQ,double
CMG)
{
	return(CLP*CO2*DGIR*PP*sqrt(UU*UU+VV*VV+WW*WW)*X1+CMA*CO2*sqrt(UU*UU+VV*VV+WW*WW)*(VV*X3-
	WW*X2)+CMPA*CO2*DGIR*PP*((X1*X1+X2*X2+X3*X3)*UU-
	X1*(UU*X1+VV*X2+WW*X3))+(CMQ+CMG)*CO2*DGIR*sqrt(UU*UU+VV*VV+WW*WW)*((X1*X1+X2*X2+X3*X3)*H1-
	Ix/Iy*PP*X1));
}

double H2FUN (double UU,double VV,double WW,double H1,double H2,double H3,double X1,double X2,double
X3,double CO2,double DGIR,double Ix,double Iy,double PP,double CLP,double CMA,double CMPA,double CMQ,double
CMG)
{
	return(CLP*CO2*DGIR*PP*sqrt(UU*UU+VV*VV+WW*WW)*X2+CMA*CO2*sqrt(UU*UU+VV*VV+WW*WW)*(WW*X1-
	UU*X3)+CMPA*CO2*DGIR*PP*((X1*X1+X2*X2+X3*X3)*VV-
	X2*(UU*X1+VV*X2+WW*X3))+(CMQ+CMG)*CO2*DGIR*sqrt(UU*UU+VV*VV+WW*WW)*((X1*X1+X2*X2+X3*X3)*H2-
	Ix/Iy*PP*X2));
}

double H3FUN (double UU,double VV,double WW,double H1,double H2,double H3,double X1,double X2,double
X3,double CO2,double DGIR,double Ix,double Iy,double PP,double CLP,double CMA,double CMPA,double CMQ,double
CMG)
{
	return(CLP*CO2*DGIR*PP*sqrt(UU*UU+VV*VV+WW*WW)*X3+CMA*CO2*sqrt(UU*UU+VV*VV+WW*WW)*(UU*X2-
	VV*X1)+CMPA*CO2*DGIR*PP*((X1*X1+X2*X2+X3*X3)*WW-
	X3*(UU*X1+VV*X2+WW*X3))+(CMQ+CMG)*CO2*DGIR*sqrt(UU*UU+VV*VV+WW*WW)*((X1*X1+X2*X2+X3*X3)*H3-
	Ix/Iy*PP*X3));
}

double X1FUN (double H1,double H2,double H3,double X1,double X2,double X3)
{
	return(H2*X3-H3*X2);
}

double X2FUN (double H1,double H2,double H3,double X1,double X2,double X3)
{
	return(H3*X1-H1*X3);
}

double X3FUN (double H1,double H2,double H3,double X1,double X2,double X3)
{
	return(H1*X2-H2*X1);
}

double RAD(double MIL)
{
	return (MIL*M_PI/3200);
}