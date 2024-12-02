#include<stdio.h>
long int func_factorial(long int n[],int k_counter){
	long int tmp,x;
	tmp=n[k_counter];
	int i;
	for(i=1,x=1;i<=tmp;i++){
		x=x*i;
	}
	return x;
}
main(){
	long int n[1000];
	int i_counter;
	while(1){
		scanf("%lu",&n[i_counter]);
		if(n[i_counter]==0){
			break;
		}
		i_counter++;
	}
	long int factorial[1000];
	int j_counter;
	for(j_counter=0;j_counter<i_counter;j_counter++){
		factorial[j_counter]=func_factorial(n,j_counter);
	}
	i_counter=0;
	int counter[1000],k_counter;
	for(k_counter=0;k_counter<j_counter;k_counter++){
		while(1){
			if((factorial[k_counter]%10)!=0){
				break;
			}
			factorial[k_counter]=factorial[k_counter]/10;
			counter[k_counter]=i_counter;
			i_counter++;
		}
	}
	for(i_counter=0;i_counter<j_counter;i_counter++){
		printf("%d\n",counter[i_counter]);
	}
	return 0;
}