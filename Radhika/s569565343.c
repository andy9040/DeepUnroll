#include<stdio.h>
int main(){
int a,b,i,n,q=0,m=0,r,p,l;
scanf("%d %d",&a,&b);
p=1;
while(p<=b){
    q++;
    p=p*2;
    if(q>a){
        break;
    }
}r=a-q;
l=(b*r+p);
   printf("%d",l);
return 0;
}
