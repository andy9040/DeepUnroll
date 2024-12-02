/*
  AOJ 0157
  Title:Russian Dolls
  @kankichi573
*/
#include <stdio.h>
#define max(x,y) (((x)>(y))?(x):(y))
int n,m,total;
struct doll
{
  int h;
  int r;
  int nextp;
  int memo;
} dolls[200];

int compare_doll(const void *a, const void *b)
{
  if (((struct doll *)b)->h > ((struct doll *)a)->h)
    return(-1);
  if (((struct doll *)b)->h < ((struct doll *)a)->h)
    return(1);
  if (((struct doll *)b)->r > ((struct doll *)a)->r)
    return(-1);
  if (((struct doll *)b)->r < ((struct doll *)a)->r)
    return(1);
  return(0);
}

int solve(int hh,int rr,int index)
{
  int ret1,ret2,ret;

  if(index==total)
    return(0);
  if(dolls[index].h > hh && dolls[index].r > rr)
    {
    if(dolls[index].memo > 0)
      ret1=dolls[index].memo;
    else
      ret1=1+solve(dolls[index].h, dolls[index].r ,dolls[index].nextp);
    }
  else
    ret1=0;
  ret2=solve(hh,rr,index+1);
  ret=max(ret1,ret2);
  dolls[index].memo = ret;
  return(ret);
}
void dump()
{
  int i;

  for(i=0;i<total;i++)
    printf("%d :%d %d %d\n",i,dolls[i].h,dolls[i].r,dolls[i].nextp);
  printf("---------\n");
}
void calc_nextptr()
{
  int i,j,rr;

  for(i=0;i<total;i++)
    {
      dolls[i].nextp=total;
      rr = dolls[i].r;
      for(j=i+1;j<total;j++)
	if(dolls[j].r > rr)
	  {
	    dolls[i].nextp=j;
	    break;
	  }
    }
}
main()
{
  int i;

  while(scanf("%d",&n) && n)
    {
      for(i=0;i<n;i++)
	scanf("%d %d",&dolls[i].h,&dolls[i].r);
      scanf("%d",&m);
      for(i=0;i<m;i++)
	scanf("%d %d",&dolls[i+n].h,&dolls[i+n].r);
      total=n+m;
      for(i=0;i<total;i++)
	dolls[i].memo=0;
      //dump();
      qsort(dolls,total,sizeof(struct doll),compare_doll);
      //dump();
      calc_nextptr();
      dump();
      int ret=solve(0,0,0);
      printf("%d\n",ret);
      
    }
  return(0);
}