#include <stdio.h>
#include <string.h>
  int main(){
	  char x[10];
	  int j;
	  scanf("%s",&x);
	    j =  strlen(x);
	  int n,i,k,l,m,o;
	  int num=0,sum=0;
	  scanf("%d",&n);
	  char a[100][10],z;
	  aaa:
	  for(i=0;i<n;i++){
		  for(o=0;o<10;j++){
			  scanf("%c",&z);
			  a[i][o]=z;
		  }
		  for(k=0;k<10;k++){
			  for(l=0;l<j;l++){
				  m = k+l;
				  m = m%10;
				  if(a[i][m] != x[l]){
					  num=1;
					  break;
				  }
			  }
			  if(num==0){
				  sum++;
				  i++;
				  goto aaa;
			  }
			  num=0;
		  }
	  }
	  printf("%d\n",sum);
	  return 0;
  }