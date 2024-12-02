#include<stdio.h>

int change(int j,int k);

int main(void)
{
  int x,n,i,j,z,judge,num=0;
  int *p;
  
  scanf("%d",&x);
  scanf("%d",&n);
	
	p=(int *)malloc(sizeof(int)*n);
  
  if(n==0)
  {
    printf("%d",x);
  	free(p);
    return 0;
  }
  
  
  for(i=0;i<n;i++)
	{
    scanf("%d",&p[i]);
	 }
	
	
	for(j=1;j<=100;j++)
	{
		for(i=0;i<n;i++)
		{
			num=0;
		
			if(j==p[i])
			{
				num++;
				break;
			}
		}
		
		if(num==1)
		{
			continue;
		}
		
		if(j==1)
		{
			z=change(x,j);
			judge=j;
		}else if(num==1)
		{
			continue;
		}else if(change(x,j)<change(x,judge))
		{
			z=change(x,j);
			judge=j;
		}
	}
  
  printf("%d",judge);
	
	free(p);
	
  return 0;
}

int change(int j,int k)
{
  if(j>=k)
  {
	
    return j-k;
  }else
  {
    
    return k-j;
  }
}