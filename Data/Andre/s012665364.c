#include<stdio.h>
int main(){
int H,W,re1,re2,re3;
scanf("%d %d",&H,&W);
re1=H*W;
re3=re1;  
re2=re1%2;
if(re2!=0){
	re1=re3/2+1;
}  
else{
  	re1=re3/2;
  }
printf("%d",re1);
return 0;
}