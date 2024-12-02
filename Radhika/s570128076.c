#include<stdio.h>
int main(){
int i,input,a[4],b;
for(i=0;i<4;i++){
	scanf("%d%d",&input,&b);
	case (input){
		case 1:
			a[i]=6000*b;
			break;
		case 2:
			a[i]=4000*b;
			break;
		case 3:
			a[i]=3000*b;
			break;
		case 4:
			a[i]=2000*b;
			break;
	}
}
for(i=0;i<4;i++){
	printf("%d\n",a[i]);
}
return 0;
}