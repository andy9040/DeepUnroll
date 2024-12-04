#include<stdio.h>
#include<math.h>
int main(){
 int i,j,k;
 int N[1000];
 int S[100];
 double A[1000],B[1000];
 double V[1000];

 for(i=1;i<1000;i++){
  scanf("%d",&N[i]);


  for(j=1;j<=N[i]-1;j++){
   scanf("%d ",&S[j]);
   A[i]+=pow(S[j],2);
   B[i]+=S[j];
  }
   scanf("%d\n",&S[N[i]]);
   A[i]+=pow(S[N[i]],2);
   B[i]+=S[N[i]];

   V[i]=sqrt(A[i]/N[i]-pow(B[i]/N[i],2));

  if(N[i]==0){
   k=i;
   break;
  }

 }

 for(i=1;i<k;i++){
  printf("%lf\n",V[i]);
 }



return 0;
}