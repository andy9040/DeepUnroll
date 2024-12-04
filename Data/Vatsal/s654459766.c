#include <stdio.h>
int main(void){
	int n,w,cont;
	scanf("%d", &n);
	long arr[n],tmp,maior=0;
	for(int i=0;i<n;++i){
		scanf("%d",&tmp);
		arr[i]=tmp;
		if(tmp>=maior)maior=tmp;
	}
	while(maior>0){
		cont=0;
		for(w=0;w<n;w++){
			if((arr[w]%maior)!=0){
				cont++;
			}
			if(cont>1)break;
		}
		if(cont<=1)break;
		maior--;
	}
	printf("%d\n",maior);
	return 0;
}