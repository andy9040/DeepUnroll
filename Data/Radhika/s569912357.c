/*
  AOJ 2138
  Title:Vending Machine
  @kankichi573
*/
#include <stdio.h>
#include <string.h>

#define LIMIT 100000
int n,m;
int denomi[10];
int table[LIMIT+1];
int gr;

int min(int x,int y)
{
  if(x<y)
    return(x);
  else
    return(y);

}
int max(int x,int y)
{
  if(x>y)
    return(x);
  else
    return(y);

}

void dump()
{
  int i;
  for(i=1;i<=m;i++)
    if(table[i]<LIMIT)
      printf("%d:%d,",i,table[i]);
  printf("\n");
}

greed(int kin[],int n,int m)
{
  int highest,min_,i,count;

  highest=kin[0];
  //printf("gr=%d [%d][%d]\n",m,highest,n);
  if(m==0)
    return(0);
  if(m < highest && n>1)
    return(greed(kin+1,n-1,m));
  if(n==1)
    {
      if((m%highest)==0)
	return(m/highest);
      else
	return(LIMIT);
    }
  min_=LIMIT;
  for(i=m/highest;i>=0;i--)
    {
      //printf("i=%d\n",i);
      count=max(i,greed(kin+1,n-1,m-i*highest));
      if(min_>count)
	{
	  min_=count;
	  break;
	}
    }
  return(min_);
}


void solve()
{
  int i,j,k,kin,wk;

  for(i=1;i<=m;i++)
    table[i]=LIMIT;

  kin=denomi[0];
  for(i=0;i*kin<=m;i++)
    table[i*kin]=i;
  //dump();
  for(i=1;i<n;i++)
    {
      kin=denomi[i];
      for(j=m;j>=0;j--)
	if(table[j]!=LIMIT)
	  {
	    for(k=1;j+kin*k<=m && k<=gr;k++)
	      {
		if(table[j+kin*k]>(wk=max(k,table[j])))
		  table[j+kin*k] = wk;
		else
		  break;
	      }
	  }
      //dump();
    }
    
}


int compare(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}


main()
{
  int i,ret;
  while(scanf("%d %d",&n,&m) && (n||m))
    {
      for(i=0;i<n;i++)
	scanf("%d",&denomi[i]);
      qsort(denomi,n,sizeof(int),compare);
      gr=greed(denomi,n,m);
      //printf("greed=%d\n",gr);
      solve();
      printf("%d\n",table[m]);
    }
  return(0);
}