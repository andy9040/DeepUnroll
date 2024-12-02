#include<stdio.h>

int main(void)
{
  int n;
  int i;

  for(;;){

    int j=0,k,p=0,l,o;
    scanf("%d",&n);
    if(n==0)
      break;

    if(n%2==1)
      {
	o=2;
      }
    else
      {
	o=1;
      }
    for(i=n;i<=2*n;i=i+o)
      {
	if(i>=3)
	  {
	    l=i/2;
	  }
	else
	  {
	    l=i;
	  }
	for(k=1;k<=l;k++)
	  {
	    if(i%k==0)
	      {
		j++;
		if(j>2)
		  break;
	      }
	  }
	if(j==1)
	  {
	    p++;
	  }
	j=0;
	if(i%2==1)
	  o=2;
      }
    printf("%d\n",p);
  }

    return 0;
}