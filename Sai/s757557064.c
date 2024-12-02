pln[8][9];
main(i,j,c,f){
	while(1){
		for(i=0;i<8;i++)for(j=0;j<9;j++)if((pln[i][j]=getchar())==-1)exit(0);
		for(i=0;i<8;i++)for(j=0;j<8;j++)pln[i][j]-='0';
		getchar();
		f=1;
		for(i=0;f&&i<8;i++)for(j=0;f&&j<8;j++)
			if(pln[i][j]){
				if     (i<=4 && pln[i+3][j])	c='B';
				else if(j<=4 && pln[i][j+3])	c='C';
				else if(i<=5 && 2<=j && pln[i+2][j-1])	c='D';
				else if(i<=6 && j<=5 && pln[i+1][j+2])	c='E';
				else if(i<=5 && j<=6 && pln[i+2][j+1])	c='F';
				else if(i<=6 && j<=6 &&!pln[i+1][j+1])	c='G';
				else	c='A';
				f=0;
			}
		printf("%c\n",c);
	}
}