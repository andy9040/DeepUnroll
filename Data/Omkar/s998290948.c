/*
  AOJ 2052
  Title:optimal rest
  @kankichi573
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char rest_table[2000][80];

struct kf_st
{
  int  len;
  char kigou[80];
} kyuufu[28];

void make_kyuufu()
{
  int i,j,k;

  memset(kyuufu,0,sizeof(kyuufu));
  for(i=1,k=0;i<=64;i*=2)
    {
      kyuufu[k].len = 64/i;
      sprintf(&kyuufu[k].kigou[0],"R%d",i);
      k++;
      
      for(j=i;j<64;j*=2)
	{
	  memcpy(&kyuufu[k],&kyuufu[k-1],sizeof(struct kf_st));
	  strcat(&kyuufu[k].kigou[0],".");
	  kyuufu[k].len += 32/j;
	  k++;
	}
      
    }
}

make_rest_table()
{
  char buf[80];
  int i,j,idx;

  for(i=0;i<2000;i++)
    {
      for(j=0;j<28;j++)
	{
	  idx=i+kyuufu[j].len;
	  if(idx >= 2000)
	    goto NEXT;
	  
	  if(strlen(&rest_table[i][0])+strlen(&kyuufu[j].kigou[0]) > 79)
	      continue;

	  sprintf(buf,"%s%s",&rest_table[i][0],&kyuufu[j].kigou[0]);

	  if(strlen(&rest_table[idx][0])==0||strlen(buf) < strlen(&rest_table[idx][0]) ||
	     ((strlen(buf) == strlen(&rest_table[idx][0])) && (-1==strcmp(buf,&rest_table[idx][0]))))
	    {
	      strcpy(&rest_table[idx][0],buf);
	    }
	NEXT: ;
	}
    }
}

int calc1(char s[])
{
  char buf[7];
  int n,ret,ret1,i,dots;
  
  memset(buf,0,7);
  sscanf(s,"%d%[.]",&n,buf);
  ret = 64/n;
  ret1=ret;
  dots=strlen(buf);
  for(i=0;i<dots;i++)
    {
      ret /= 2;
      ret1 += ret;
    }
  return(ret1);
}

int calc_rest(char s[])
{
  char *p;
  int r,ret;

  p=strtok(s,"R\r\0");
  ret=0;
  while(p)
    {
      r = calc1(p);
      ret += r;
      //printf("r=%d\n",r);
      p=strtok(NULL,"R\r\0");
    }

  return(ret);
}

void dump_k()
{
  int i;
  for(i=0;i<28;i++)
    printf("%d:%s\n",kyuufu[i].len,&kyuufu[i].kigou[0]);
}

dump()
{
  int i,j;

  for(i=0;i<2000;i++)
    if(rest_table[i][0])
      printf("%d:%s\n",i,rest_table[i]);
      
}

char *print_former(char s[])
{
  char *p;

  p=strchr(s,'R');
  do
    {
      if(p[1]=='1' && p[2]=='.')
	{
	  printf("R1");
	  p+=2;
	  while(*p++=='.')
	    printf(".");
	}
      else
	return(p);
    }
  while(p=strchr(p-1,'R'));
  return(NULL);
}

main()
{
  int i,d,l,l1;
  char input[100001],*rest,*last;

  make_kyuufu();
  make_rest_table();
  scanf("%d",&d);
  for(i=0;i<d;i++)
    {
      scanf("%s",input);
      l1=l=calc_rest(input);
      //printf("%d\n",l);

      while(l>=2000)
	l -= 96;
      
      rest=&rest_table[l][0];

      last=print_former(rest);

      
      while(l1>=2000)
	{
	  printf("R1.");
	  l1 -= 96;
	}
      
      if(last)
	printf("%s\n",last);
      else
	printf("\n");
    }
  return(0);
}