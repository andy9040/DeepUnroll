#include<stdio.h>
int main(void)
{
	int h,w,i,j,k;
	for(k=0;;k++){
		scanf("%d %d",&h,&w);
		
		if(h==0&&w==0){
			break;
		}
		
		for(i=0;i<h;i++){
			for(j=0;j<w;j++){
				if(i==0||j==0||j==w-1||i==h-1){
					printf("#");
				}
				else{
					printf(".");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
}