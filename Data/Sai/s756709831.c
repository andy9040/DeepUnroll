#include<stdio.h>
#include<stdlib.h>

int main(){
		int n,i;
		scanf("%d",&n);
		long xyh[n][3];
		for(i=0;i<n;i++){
				scanf("%ld%ld%ld",&xyh[i][0],&xyh[i][1],&xyh[i][2]);
		}
		int cx,cy,flag=0;long h,tmp;
		for(cx=0;cx<=100;cx++){
				for(cy=0;cy<=100;cy++){
				//		printf("%d %d\n",cx,cy);
						flag=0;
						for(i=0;i<n;i++){
								h=xyh[i][2]+abs(xyh[i][0]-cx)+abs(xyh[i][1]-cy);
								if(h-abs(xyh[i][0]-cx)-abs(xyh[i][1]-cy)<0){
										flag=1;
										break;
								}
								if(i==0){
										tmp=h;
								}
								if(tmp!=h){
										flag=1;
										break;
								}
						}
								if(flag==0){
										printf("%d %d %ld",cx,cy,tmp);
										return 0;
								}
				}
/*						int tmp=xyh[i][2]-abs(xyh[j][0]-xyh[i][0])-abs(xyh[j][1]-xyh[i][1]);
						if(tmp<0)tmp=0;
						if(xyh[j][2]=!tmp)break;*/
		}
}
