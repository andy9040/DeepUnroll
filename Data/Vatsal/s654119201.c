#include <stdio.h>

int main(void)
{
  int i,l;
  int flag=0;
  int n[1000];
  do{
  scanf("%d", &l);
  }while(l<1||l>1000);
  
  for(i=0;i<l;i++)
  {
    do{
    scanf("%d" ,&n[i]);
    }while(n[i]<1||n[i]>100);
  } 
for(i=0;i<l;i++)
{
if(n[i]%2==0)
{
	if(n[i]%3!=0&&n[i]%5!=0)
	{
		flag=1;
	}
}
}
  
  if(flag==0)
    printf("APPROVED");
  else
    printf("DENIED");
return 0;
}