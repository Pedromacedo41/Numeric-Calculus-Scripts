
Arquivodefuncoes;
arqsaida=fopen("saida3.txt","w");
CondicoesIniciais3;
format long;

while (YY>=0)
    if ((0<=YY) && (YY<2000)) 
        Wx = Wx0a2000; Wy = Wy0a2000; Wz = Wz0a2000;
    endif
		if ((2000<=YY) && (YY<4000)) 
        Wx = Wx2000a4000; Wy = Wy2000a4000; Wz = Wz2000a4000;
    endif
		if ((4000<=YY) && (YY<6000)) 
        Wx = Wx4000a6000; Wy = Wy4000a6000; Wz = Wz4000a6000;
    endif
		if ((6000<=YY) && (YY<8000)) 
        Wx = Wx6000a8000; Wy = Wy6000a8000; Wz = Wz6000a8000;
    endif
		XA = XX;
		YA = YY;
		ZA = ZZ;
		MACH = Mach(TempFahr,YY,sqrt(UU*UU+VV*VV+WW*WW));
		CD = InterpCd(Cdtab,MACH);
		CLA = InterpCd(Cnatab,MACH)*(UU*X1+VV*X2+WW*X3)/sqrt((UU*UU+VV*VV+WW*WW))+CD;
		CMA = InterpCd(Cmatab,MACH);
		CNPA = -InterpCd(Cnpatab,MACH);
		CNQ = 0;
		CNA = 0;
		CLP = InterpCd(Clptab,MACH);
		CMQ = InterpCd(Cmqtab,MACH);
		CMG = 0;
		ATQ = acos((UU*X1+VV*X2+WW*X3)/sqrt((UU*UU+VV*VV+WW*WW)))*180/pi;
		if ((0<=ATQ) && (ATQ<1)) 
      CMPA = (InterpCd(CnpAT1,MACH)-0)*(ATQ-0)/(1-0)+0;
    endif
		if ((1<=ATQ) && (ATQ<2)) 
      CMPA = (InterpCd(CnpAT2,MACH)-InterpCd(CnpAT1,MACH))*(ATQ-1)/(2-1)+InterpCnp(CnpAT1,MACH);
		endif
    if ((2<=ATQ) && (ATQ<3)) 
      CMPA = (InterpCd(CnpAT3,MACH)-InterpCd(CnpAT2,MACH))*(ATQ-2)/(3-2)+InterpCd(CnpAT2,MACH);
    endif
		if ((3<=ATQ) && (ATQ<4)) 
      CMPA = (InterpCd(CnpAT4,MACH)-InterpCd(CnpAT3,MACH))*(ATQ-3)/(4-3)+InterpCd(CnpAT3,MACH);
		endif
    if ((4<=ATQ) && (ATQ<5)) 
      CMPA = (InterpCd(CnpAT5,MACH)-InterpCd(CnpAT4,MACH))*(ATQ-4)/(5-4)+InterpCd(CnpAT4,MACH);
		endif
    if ((5<=ATQ) && (ATQ<7.5)) 
      CMPA = (InterpCd(CnpAT7v5,MACH)-InterpCd(CnpAT5,MACH))*(ATQ-5)/(7.5-5)+InterpCd(CnpAT5,MACH);
		endif
    if ((7.5<=ATQ) && (ATQ<10)) 
      CMPA = (InterpCd(CnpAT10,MACH)-InterpCd(CnpAT7v5,MACH))*(ATQ-7.5)/(10-7.5)+InterpCd(CnpAT7v5,MACH);
		endif
    if ((10<=ATQ) && (ATQ<15)) 
      CMPA = (InterpCd(CnpAT15,MACH)-InterpCd(CnpAT10,MACH))*(ATQ-10)/(15-10)+InterpCd(CnpAT10,MACH);
		endif
    if ((15<=ATQ) && (ATQ<20)) 
      CMPA = (InterpCd(CnpAT20,MACH)-InterpCd(CnpAT15,MACH))*(ATQ-15)/(20-15)+InterpCd(CnpAT15,MACH);
		endif
    if ((20<=ATQ) && (ATQ<30)) 
      CMPA = (InterpCd(CnpAT30,MACH)-InterpCd(CnpAT20,MACH))*(ATQ-20)/(30-20)+InterpCd(CnpAT20,MACH);
		endif
    if ((30<=ATQ) && (ATQ<60)) 
      CMPA = (InterpCd(CnpAT60,MACH)-InterpCd(CnpAT30,MACH))*(ATQ-30)/(60-30)+InterpCd(CnpAT30,MACH);
		endif
    if ((60<=ATQ) && (ATQ<90)) 
      CMPA = (InterpCd(CnpAT90,MACH)-InterpCd(CnpAT60,MACH))*(ATQ-60)/(90-60)+InterpCd(CnpAT60,MACH);
		endif
    CO1 = Ro(YY)*S/2/M;
		CO2 = Ro(YY)*S*DGIR/2/Iy;
		PP = Iy/Ix*(H1*X1+H2*X2+H3*X3);
		%Bloco RUNGE-KUTTA de quarta ordem
		K1 = H*UU;
		L1 = H*XFUN3(UU,VV,WW,H1,H2,H3,X1,X2,X3,CO1,DGIR,PP,G,CD,CLA,CNPA,CNQ,CNA);
		M1 = H*VV;
		N1 = H*YFUN3(UU,VV,WW,H1,H2,H3,X1,X2,X3,CO1,DGIR,PP,G,CD,CLA,CNPA,CNQ,CNA);
		O1 = H*WW;
		P1 = H*ZFUN3(UU,VV,WW,H1,H2,H3,X1,X2,X3,CO1,DGIR,PP,G,CD,CLA,CNPA,CNQ,CNA);
		Q1 = H*H1FUN(UU,VV,WW,H1,H2,H3,X1,X2,X3,CO2,DGIR,Ix,Iy,PP,CLP,CMA,CMPA,CMQ,CMG);
		R1 = H*H2FUN(UU,VV,WW,H1,H2,H3,X1,X2,X3,CO2,DGIR,Ix,Iy,PP,CLP,CMA,CMPA,CMQ,CMG);
		S1 = H*H3FUN(UU,VV,WW,H1,H2,H3,X1,X2,X3,CO2,DGIR,Ix,Iy,PP,CLP,CMA,CMPA,CMQ,CMG);
		T1 = H*X1FUN(H1,H2,H3,X1,X2,X3);
		U1 = H*X2FUN(H1,H2,H3,X1,X2,X3);
		V1 = H*X3FUN(H1,H2,H3,X1,X2,X3);
		K2 = H*(UU+L1/2);
		L2 =H*XFUN3(UU+L1/2,VV+N1/2,WW+P1/2,H1+Q1/2,H2+R1/2,H3+S1/2,X1+T1/2,X2+U1/2,X3+V1/2,CO1,DGIR,PP,G,CD,CLA,CNPA,CNQ,CNA);
		M2 = H*(VV+N1/2);
		N2 =H*YFUN3(UU+L1/2,VV+N1/2,WW+P1/2,H1+Q1/2,H2+R1/2,H3+S1/2,X1+T1/2,X2+U1/2,X3+V1/2,CO1,DGIR,PP,G,CD,CLA,CNPA,CNQ,CNA);
		O2 = H*(WW+P1/2);
		P2 =H*ZFUN3(UU+L1/2,VV+N1/2,WW+P1/2,H1+Q1/2,H2+R1/2,H3+S1/2,X1+T1/2,X2+U1/2,X3+V1/2,CO1,DGIR,PP,G,CD,CLA,CNPA,CNQ,CNA);
		Q2 =H*H1FUN(UU+L1/2,VV+N1/2,WW+P1/2,H1+Q1/2,H2+R1/2,H3+S1/2,X1+T1/2,X2+U1/2,X3+V1/2,CO2,DGIR,Ix,Iy,PP,CLP,CMA,CMPA,CMQ,CMG);
		R2 =H*H2FUN(UU+L1/2,VV+N1/2,WW+P1/2,H1+Q1/2,H2+R1/2,H3+S1/2,X1+T1/2,X2+U1/2,X3+V1/2,CO2,DGIR,Ix,Iy,PP,CLP,CMA,CMPA,CMQ,CMG);
		S2 =H*H3FUN(UU+L1/2,VV+N1/2,WW+P1/2,H1+Q1/2,H2+R1/2,H3+S1/2,X1+T1/2,X2+U1/2,X3+V1/2,CO2,DGIR,Ix,Iy,PP,CLP,CMA,CMPA,CMQ,CMG);
		T2 = H*X1FUN(H1+Q1/2,H2+R1/2,H3+S1/2,X1+T1/2,X2+U1/2,X3+V1/2);
		U2 = H*X2FUN(H1+Q1/2,H2+R1/2,H3+S1/2,X1+T1/2,X2+U1/2,X3+V1/2);
		V2 = H*X3FUN(H1+Q1/2,H2+R1/2,H3+S1/2,X1+T1/2,X2+U1/2,X3+V1/2);
		K3 = H*(UU+L2/2);
		L3 =H*XFUN(UU+L2/2,VV+N2/2,WW+P2/2,H1+Q2/2,H2+R2/2,H3+S2/2,X1+T2/2,X2+U2/2,X3+V2/2,CO1,DGIR,PP,G,CD,CLA,CNPA,CNQ,CNA);
		M3 = H*(VV+N2/2);
		N3 =H*YFUN(UU+L2/2,VV+N2/2,WW+P2/2,H1+Q2/2,H2+R2/2,H3+S2/2,X1+T2/2,X2+U2/2,X3+V2/2,CO1,DGIR,PP,G,CD,CLA,CNPA,CNQ,CNA);
		O3 = H*(WW+P2/2);
		P3 =H*ZFUN(UU+L2/2,VV+N2/2,WW+P2/2,H1+Q2/2,H2+R2/2,H3+S2/2,X1+T2/2,X2+U2/2,X3+V2/2,CO1,DGIR,PP,G,CD,CLA,CNPA,CNQ,CNA);
		Q3 =H*H1FUN(UU+L2/2,VV+N2/2,WW+P2/2,H1+Q2/2,H2+R2/2,H3+S2/2,X1+T2/2,X2+U2/2,X3+V2/2,CO2,DGIR,Ix,Iy,PP,CLP,CMA,CMPA,CMQ,CMG);
		R3 =H*H2FUN(UU+L2/2,VV+N2/2,WW+P2/2,H1+Q2/2,H2+R2/2,H3+S2/2,X1+T2/2,X2+U2/2,X3+V2/2,CO2,DGIR,Ix,Iy,PP,CLP,CMA,CMPA,CMQ,CMG);
		S3 =H*H3FUN(UU+L2/2,VV+N2/2,WW+P2/2,H1+Q2/2,H2+R2/2,H3+S2/2,X1+T2/2,X2+U2/2,X3+V2/2,CO2,DGIR,Ix,Iy,PP,CLP,CMA,CMPA,CMQ,CMG);
		T3 = H*X1FUN(H1+Q2/2,H2+R2/2,H3+S2/2,X1+T2/2,X2+U2/2,X3+V2/2);
		U3 = H*X2FUN(H1+Q2/2,H2+R2/2,H3+S2/2,X1+T2/2,X2+U2/2,X3+V2/2);
		V3 = H*X3FUN(H1+Q2/2,H2+R2/2,H3+S2/2,X1+T2/2,X2+U2/2,X3+V2/2);
		K4 = H*(UU+L3);
		L4 =H*XFUN3(UU+L3,VV+N3,WW+P3,H1+Q3,H2+R3,H3+S3,X1+T3,X2+U3,X3+V3,CO1,DGIR,PP,G,CD,CLA,CNPA,CNQ,CNA);
		M4 = H*(VV+N3);
		N4 =H*YFUN3(UU+L3,VV+N3,WW+P3,H1+Q3,H2+R3,H3+S3,X1+T3,X2+U3,X3+V3,CO1,DGIR,PP,G,CD,CLA,CNPA,CNQ,CNA);
		O4 = H*(WW+P3);
		P4 =H*ZFUN(UU+L3,VV+N3,WW+P3,H1+Q3,H2+R3,H3+S3,X1+T3,X2+U3,X3+V3,CO1,DGIR,PP,G,CD,CLA,CNPA,CNQ,CNA);
		Q4 =H*H1FUN(UU+L3,VV+N3,WW+P3,H1+Q3,H2+R3,H3+S3,X1+T3,X2+U3,X3+V3,CO2,DGIR,Ix,Iy,PP,CLP,CMA,CMPA,CMQ,CMG);
		R4 =H*H2FUN(UU+L3,VV+N3,WW+P3,H1+Q3,H2+R3,H3+S3,X1+T3,X2+U3,X3+V3,CO2,DGIR,Ix,Iy,PP,CLP,CMA,CMPA,CMQ,CMG);
		S4 =H*H3FUN(UU+L3,VV+N3,WW+P3,H1+Q3,H2+R3,H3+S3,X1+T3,X2+U3,X3+V3,CO2,DGIR,Ix,Iy,PP,CLP,CMA,CMPA,CMQ,CMG);
		T4 = H*X1FUN(H1+Q3,H2+R3,H3+S3,X1+T3,X2+U3,X3+V3);
		U4 = H*X2FUN(H1+Q3,H2+R3,H3+S3,X1+T3,X2+U3,X3+V3);
		V4 = H*X3FUN(H1+Q3,H2+R3,H3+S3,X1+T3,X2+U3,X3+V3);
		TT = TT+H;
		XX = XX+(K1+2*(K2+K3)+K4)/6+Wx*H; %correcao devido ao vento
		UU = UU+(L1+2*(L2+L3)+L4)/6;
		YY = YY+(M1+2*(M2+M3)+M4)/6+Wy*H; %correcao devido ao vento
		if (((M1+2*(M2+M3)+M4)/6)>0) 
      FLECHA = YY;
    endif
		VV = VV+(N1+2*(N2+N3)+N4)/6;
		ZZ = ZZ+(O1+2*(O2+O3)+O4)/6+Wz*H; %correcao devido ao vento
		WW = WW+(P1+2*(P2+P3)+P4)/6;
		H1 = H1+(Q1+2*(Q2+Q3)+Q4)/6;
		H2 = H2+(R1+2*(R2+R3)+R4)/6;
		H3 = H3+(S1+2*(S2+S3)+S4)/6;
		X1 = X1+(T1+2*(T2+T3)+T4)/6;
		X2 = X2+(U1+2*(U2+U3)+U4)/6;
		X3 = X3+(V1+2*(V2+V3)+V4)/6;
    
		YY = YY+((XX-XA)*(XX-XA)+(ZZ-ZA)*(ZZ-ZA))/12713532; %correcao devido a curvatura da terra
    G = G-2*G*(YY-YA)/6356766;  %atualizacao da gravidade
    
		fprintf (arqsaida,"%.7f\t%.7f\t%.7f\t%.7f\t%.7f\n",TT,XX,YY,ZZ,VV);
		% fprintf (arqsaida,"%lf\t%lf\t%lf\t%lf\t%lf\n",TT,XX,YY,(X1-
		% UU/sqrt(UU*UU+VV*VV+WW*WW))*WW*UU/(UU*UU+VV*VV+WW*WW)+(X2-
		% VV/sqrt(UU*UU+VV*VV+WW*WW))*WW*VV/(UU*UU+VV*VV+WW*WW)+(X3-WW/sqrt(UU*UU+VV*VV+WW*WW))*(-
		% UU*UU-VV*VV)/(UU*UU+VV*VV+WW*WW),(X1-
		% UU/sqrt(UU*UU+VV*VV+WW*WW))*VV/sqrt(UU*UU+VV*VV+WW*WW)-(X2-
		% VV/sqrt(UU*UU+VV*VV+WW*WW))*UU/sqrt(UU*UU+VV*VV+WW*WW));
endwhile

fclose(arqsaida);