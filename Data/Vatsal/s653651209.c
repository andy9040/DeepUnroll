 #include<stdio.h>
 int main(void)
 {
     int A[10000],M,N,i,j=0,k,L=0;
     scanf("%d%d",&N,&M);
     for(i=0;i<N;i++){
       scanf("%d",&A[i]);
         j=j+A[i];
     }
     for(k=0;k<=N;k++)
       if(A[k]>j/(4*M)) L++;
     if(L>=M) printf("Yes\n");
       else     printf("No\n");
     return 0;
 }