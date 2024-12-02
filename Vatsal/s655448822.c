#include <stdio.h>
int main(void)
{
int N,M,A[200],i,count=0,sum=0;

scanf("%d",&N);
scanf("%d",&M);
for(i=0;i<N;i++){
scanf("%d",&A[i]);
sum=sum+A[i];
}

for(i=0;i<N;i++){
if(A[i]>=sum/(4*M))
count++;
}

if(count>=M)
printf("Yes");
else
printf("No");


return 0;
}