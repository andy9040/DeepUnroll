#include <stdio.h>
#include <string.h>
int B[99000];
char C[100];
int main(void){
	int i,j,n,k;
	int F,L;
	char str[1000];

	fgets(str,sizeof(str),stdin);
	sscanf(str,"%d",&n); F=-1; L=0;
	for(i=0;i<n;i++){
		fgets(str,sizeof(str),stdin);
		sscanf(str,"%s %d",&C,&B[i]);
		if(strncmp(C,"deleteFirst",11)==0){
			B[F]=-1; B[i]=-1;
		}
		else if(strncmp(C,"deleteLast",10)==0){
			B[L]=-1; B[i]=-1;
		}
		else if(strncmp(C,"delete",6)==0){
			for(j=F;j>=L;j--){
				if(B[j]==B[i]){
					B[j]=-1;
					B[i]=-1; 
					break;
				}
			}
		}
		for(j=0;j<=i;j++){
			if(B[j]!=-1){
				L=j;
				break;
			}
		}
		for(j=i;j>=0;j--){
			if(B[j]!=-1){
				F=j;
				break;
			}
		}
		/*printf("L %d F %d\n",L,F);
		for(k=0;k<=i;k++){
			printf("%d ",B[k]);
		}
		printf("\n");*/
	}
	j=0;
	for(i=n-1;i>=0;i--){
		if(B[i]!=-1){
			if(j!=0 && i!=n-1) printf(" ");
			printf("%d",B[i]);
			j++;
		}
	}
	printf("\n");
	return 0;
}