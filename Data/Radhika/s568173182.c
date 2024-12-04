#include <studio.h>
int main(void){

int 1<=N,N<=100;
int 0<=A,A<=N;
int 0<=B,B<=N;
int max,min;

scanf(%d %d %d,&N,&A,&B);
if(A<B&&N>=A+B){
max=A;
min=0;
}
else if(A<B&&N<=A+B){
max=A;
min=A+B-N;
}

else if(A>B&&N>=A+B){
max=B;
min=0;
}
else if(A>B&&N<=A+B){
max=B;
min=A+B-N;
}
else if(N==A==B){
max=A;
min=A;
}
printf(“%d %d”,max,min);
return 0;
}