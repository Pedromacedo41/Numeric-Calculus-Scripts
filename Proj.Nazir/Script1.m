Arquivodefuncoes;
arqsaida=fopen("saida1.txt","w");
CondicoesIniciais1;
format long;

while (YY>=0)
    XA = XX;
		YA = YY;
		ZA = ZZ;
		MACH = Mach(TempFahr,YY,sqrt(UU*UU+VV*VV+WW*WW));
		CDP = Cdp(Ro(YY),S,InterpCd(Cdtab,MACH),M);
    
    %Bloco RUNGE-KUTTA de quarta ordem
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
		XX = XX+(K1+2*(K2+K3)+K4)/6+Wx*H; %correcao devido ao vento
		UU = UU+(L1+2*(L2+L3)+L4)/6;
		YY = YY+(M1+2*(M2+M3)+M4)/6+Wy*H; %correcao devido ao vento
		VV = VV+(N1+2*(N2+N3)+N4)/6;
		ZZ = ZZ+(O1+2*(O2+O3)+O4)/6+Wz*H; %correcao devido ao vento
		WW = WW+(P1+2*(P2+P3)+P4)/6;
		YY = YY+((XX-XA)*(XX-XA)+(ZZ-ZA)*(ZZ-ZA))/12713532; %correcao devido ao tempo
    G = G-2*G*(YY-YA)/6356766;  %atualizacao da gravidade
    
		fprintf (arqsaida,"%.7f\t%.7f\t%.7f\t%.7f\t%.7f\n",TT,XX,YY,ZZ,VV);
endwhile

fclose(arqsaida);