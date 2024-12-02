#include <stdio.h>

int main(void){
  int y,m,d;
  while(scanf("%d %d %d",&y,&m,&d)!=EOF){
    if(1868>y) printf("pre-meiji\n");
    else if(y==1868){
      if(m<9) printf("pre-meiji\n");
      else if(m>9) printf("meiji %d %d %d\n",y-1867,m,d);
      else{
	if(d<8) printf("pre-meiji\n");
	else printf("meiji %d %d %d\n",y-1867,m,d);
      }
    }else if(y<1912) printf("meiji %d %d %d\n",y-1867,m,d);
    else if(y==1912){
      if(m<7) printf("meiji %d %d %d\n",y-1867,m,d);
      else if(m>7) printf("taisho %d %d %d\n",y-1911,m,d);
      else{
	if(d<30) printf("meiji %d %d %d\n",y-1867,m,d);
	else printf("taisho %d %d %d\n",y-1911,m,d);
      }
    }else if(y<1926) printf("taisho %d %d %d\n",y-1911,m,d);
    else if(y==1926){
      if(y<12) printf("taisho %d %d %d\n",y-1911,m,d);
      else{
	if(d<25) printf("taisho %d %d %d\n",y-1911,m,d);
	else printf("showa %d %d %d\n",y-1925,m,d);
      }
    }else if(y<1989) printf("showa %d %d %d\n",y-1925,m,d);
    else if(y==1989){
      if(y>1) printf("heisei %d %d %d\n",y-1988,m,d);
      else{
	if(d<8) printf("showa %d %d %d\n",y-1925,m,d);
	else printf("heisei %d %d %d\n",y-1988,m,d);
      }
    }else printf("heisei %d %d %d\n",y-1988,m,d);
  }
  return 0;
}