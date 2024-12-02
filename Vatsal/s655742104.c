#include<stdio.h>
#include<stdlib.h>
int main()
{
  int A[3][3],N,b[10],i,j,k,num,num1,l,m,n,p,q;
  int check[3][3]={};
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      scanf("%d",&A[i][j]);
    }
  }
  scanf("%d",&N);
  for(k=0;k<N;k++)
  {
    scanf("%d",&b[k]);
  }
  num=0;
  num=0;
  for(l=0;l<N;l++)
  {
    for(m=0;m<3;m++)
    {
      for(n=0;n<3;n++)
      {
        if(b[l]==A[m][n])
        {
          check[m][n]+=1;
        }
      }
    }
  }
  
  for(p=0;p<3;p++)
  {
    for(q=0;q<3;q++)
    {
     if(check[p][q]==1)
     {
       num=num+1;
     }
     if(num==3)
     {
      printf("Yes");
       exit(0);
     }
     if(check[q][p]==1)
     {
       num1=num1+1;
     }
     if(num==3)
     {
      printf("Yes");
       exit(0);
     }
    }
  }
  if(check[0][0]==1&&check[1][1]==1&&check[2][2]==1)
  {
    printf("Yes");
    exit(0);
  }
  if(check[2][0]==1&&check[1][1]==1&&check[0][2]==1)
  {
    printf("Yes");
    exit(0);
  }
  printf("No");
}
  
      
         