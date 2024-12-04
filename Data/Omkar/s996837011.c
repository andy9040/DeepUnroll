#include<stdio.h>
#include <math.h>


int main()
{
  int A[9],N,b[10],i,cheaker[10],a;
  for(i=0;i<9;i++)
  {
    scanf("%d",&A[i]);
  }
           
  
  scanf("%d",&N);
  
  for(i=0;i<N;i++)
  {
    scanf("%d",&b[i]);
  }
  
for(i=0;i<9;i++)
  {
   for(a=0;a<N;a++)
   {
     if(A[i]==b[a])
     {
       cheaker[i+1]=1;
     }
   }
 }

 if(cheaker[1]==1 && cheaker[2]==1 && cheaker[3]==1)
  {
    printf("Yes");
    return 0;
  }

  if(cheaker[4]==1 && cheaker[5]==1 && cheaker[6]==1)
  {
    printf("Yes");
    return 0;
  }
    
  if(cheaker[7]==1 && cheaker[8]==1 && cheaker[9]==1)
  {
    printf("Yes");
    return 0;
  }
    
  if(cheaker[1]==1 && cheaker[2]==1 && cheaker[3]==1)
  {
    printf("Yes");
    return 0;
  }
  
  if(cheaker[1]==1 && cheaker[4]==1 && cheaker[7]==1)
  {
    printf("Yes");
    return 0;
  }

  if(cheaker[2]==1 && cheaker[5]==1 && cheaker[8]==1)
  {
    printf("Yes");
    return 0;
  }
  
  if(cheaker[3]==1 && cheaker[6]==1 && cheaker[9]==1)
  {
    printf("Yes");
    return 0;
  }
  
  if(cheaker[1]==1 && cheaker[5]==1 && cheaker[9]==1)
  {
    printf("Yes");
    return 0;
  }
  
  if(cheaker[3]==1 && cheaker[5]==1 && cheaker[7]==1)
  {
    printf("Yes");
    return 0;
  }
  

  printf("No");
  return 0; 
}
