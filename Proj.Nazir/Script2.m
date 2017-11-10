
Arquivodefuncoes;
arqsaida=fopen("saida2.txt","w");
CondicoesIniciais3;;
format long;


while (YY>=0)
    XA = XX;
		YA = YY;
		ZA = ZZ;
		MACH = Mach(TempFahr,YY,sqrt(UU*UU+VV*VV+WW*WW));
		CD = InterpCd(Cdtab,MACH);
		CLA = InterpCd(Cnatab, MACH)+CD;
		CMA = InterpCd(Cmatab,MACH);
		CNPA = InterpCd(Cnpatab,MACH)/2;
		CLP = InterpCd(Clptab,MACH)/2;
		KA = ka(Ro(YY),S,M);
		KB = IX/M/dgir;
		alfae = 2*IX*PP/(Ro(YY)*S*dgir*(UU*UU+VV*VV+WW*WW)*(UU*UU+VV*VV+WW*WW)*CMA)*G*sqrt(WW*WW+UU*UU);
		%Bloco RUNGE-KUTTA de quarta ordem
		K1 = H*UU;
		L1 = H*XFUN2(UU,VV,WW,PP,KA,KB,dgir,CD,CLA,CMA,CNPA,G,OM,L,AZ);
		M1 = H*VV;
		N1 = H*YFUN2(UU,VV,WW,PP,KA,KB,dgir,CD,CLA,CMA,CNPA,G,OM,L,AZ);
		O1 = H*WW;
		P1 = H*ZFUN2(UU,VV,WW,PP,KA,KB,dgir,CD,CLA,CMA,CNPA,G,OM,L,AZ);
		Q1 = H*PP;
		R1 = H*PFUN(UU,VV,WW,PP,KA,KB,dgir,M,IX,CLP);
		K2 = H*(UU+L1/2);
		L2 = H*XFUN2(UU+L1/2,VV+N1/2,WW+P1/2,PP+R1/2,KA,KB,dgir,CD,CLA,CMA,CNPA,G,OM,L,AZ);
		M2 = H*(VV+N1/2);
		N2 = H*YFUN2(UU+L1/2,VV+N1/2,WW+P1/2,PP+R1/2,KA,KB,dgir,CD,CLA,CMA,CNPA,G,OM,L,AZ);
		O2 = H*(WW+P1/2);
		P2 = H*ZFUN2(UU+L1/2,VV+N1/2,WW+P1/2,PP+R1/2,KA,KB,dgir,CD,CLA,CMA,CNPA,G,OM,L,AZ);
		Q2 = H*(PP+R1/2);
		R2 = H*PFUN(UU+L1/2,VV+N1/2,WW+P1/2,PP+R1/2,KA,KB,dgir,M,IX,CLP);
		K3 = H*(UU+L2/2);
		L3 = H*XFUN2(UU+L2/2,VV+N2/2,WW+P2/2,PP+R2/2,KA,KB,dgir,CD,CLA,CMA,CNPA,G,OM,L,AZ);
		M3 = H*(VV+N2/2);
		N3 = H*YFUN2(UU+L2/2,VV+N2/2,WW+P2/2,PP+R2/2,KA,KB,dgir,CD,CLA,CMA,CNPA,G,OM,L,AZ);
		O3 = H*(WW+P2/2);
		P3 = H*ZFUN2(UU+L2/2,VV+N2/2,WW+P2/2,PP+R2/2,KA,KB,dgir,CD,CLA,CMA,CNPA,G,OM,L,AZ);
		Q3 = H*(PP+R2/2);
		R3 = H*PFUN(UU+L2/2,VV+N2/2,WW+P2/2,PP+R2/2,KA,KB,dgir,M,IX,CLP);
		K4 = H*(UU+L3);
		L4 = H*XFUN2(UU+L3,VV+N3,WW+P3,PP+R3,KA,KB,dgir,CD,CLA,CMA,CNPA,G,OM,L,AZ);
		M4 = H*(VV+N3);
		N4 = H*YFUN2(UU+L3,VV+N3,WW+P3,PP+R3,KA,KB,dgir,CD,CLA,CMA,CNPA,G,OM,L,AZ);
		O4 = H*(WW+P3);
		P4 = H*ZFUN2(UU+L3,VV+N3,WW+P3,PP+R3,KA,KB,dgir,CD,CLA,CMA,CNPA,G,OM,L,AZ);
		Q4 = H*(PP+R3);
		R4 = H*PFUN(UU+L3,VV+N3,WW+P3,PP+R3,KA,KB,dgir,M,IX,CLP);
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
		RR = RR+(Q1+2*(Q2+Q3)+Q4)/6;
		PP = PP+(R1+2*(R2+R3)+R4)/6;
		YY = YY+((XX-XA)*(XX-XA)+(ZZ-ZA)*(ZZ-ZA))/12713532; %correcao devido a curvatura da terra
    G = G-2*G*(YY-YA)/6356766;  %atualizacao da gravidade
    
		fprintf (arqsaida,"%.7f\t%.7f\t%.7f\t%.7f\t%.7f\n",TT,XX,YY,ZZ,alfae);
endwhile

fclose(arqsaida);