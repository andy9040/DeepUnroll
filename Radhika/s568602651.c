#include <stdio.h>
int main(){
int x[3],y[3];
char b[5];
scanf ("%d%d%d",&x[0],&x[1],&x[2]);
scanf ("%d%d%d",&y[0],&y[1],&y[2]);
if(x[0] == y[2] && x[2] == y[0]){
 sprintf( b,"yes");
}else{
sprintf(b,"no");
}
printf("%s",b);
return 0;
}