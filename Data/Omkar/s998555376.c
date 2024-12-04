#include<stdio.h>
main(){
  int n,k,i,j,max,a,b,cnt;
  int x[]={0,1,1,1};
  int y[]={1,1,0,-1};
  char str[256][256];
  while(1){
    scanf("%d",&n);
    if(n==0)break;
    max=0;
    for(i=0;i<n;i++){
      scanf("%s",str[i]);
    }
    for(i=0;i<n;i++){
      for(j=0;j<n;j++){
	if(str[i][j]=='1'){
	  for(k=0;k<4;k++){
	    for(cnt=1,a=i+x[k],b=j+y[k];a>=0&&b>=0&&a<n&&b<n;a+=x[k],b+=y[k],cnt++){
	      if(str[a][b]=='0')break;
	    }
	    if(cnt>max){
	      max=cnt;
	    }
	  }
	}
      }
    }
    printf("%d\n",max);
  }
  return 0;
}