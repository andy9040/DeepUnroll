#include <stdlib.h>
#include <stdio.h>

main()
{
  int n,m,a,b,x,y,i,l_time,l_lev,count,tmp_time,com;
  while(1)
    {
      scanf("%d %d",&n,&m);
      if(n==0)
	exit(0);
      l_time=0;
      l_lev=0;
      com=0;
      for(i=0;i<n;i++)
	{
	  scanf("%d",&a);
	  if(l_lev==0)	  
	    {
	      l_lev=a;
	      x=m/a;
	      count = i + 1;
	      l_time = a*x;
	    }
	  else
	    {
	      //  printf("else\n");
	      tmp_time=0;
	      while(l_time>tmp_time)
		{
		  if(tmp_time+a>m)
		    {
		      break;
		    }
		    tmp_time+=a;
		}
	      //	      printf("else2\n");
	      if(l_time==tmp_time)
		{
		  //printf("else3\n");
		  if(l_lev<a)
		    continue;
		  else if(l_lev==a)
		    {
		      com++;
		      continue;
		    }
		}
	      //	      printf("else4\n");
	      while(tmp_time+a<m)
		{
		  tmp_time+=a;
		  if(tmp_time>l_time)
		    break;
		}
	      //      printf("else5 t_t=%d\n",tmp_time);
	      if(tmp_time>l_time)
		continue;
	      //printf("else6\n");
	      if(a==l_lev)
		com++;
	      else
		{
		  l_lev=a;
		  count = i + 1;
		  l_time = tmp_time;
		  com=0;
		}	      
	    }
	  
	  
	  //printf("tmp = %d com = %d  lev = %d time = %d count =%d\n",tmp_time,com,l_lev,l_time,count);
	}
      if(com>0)
	count=n;
      printf("%d\n",count);
    }
}