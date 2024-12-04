#include <stdio.h>

int main(void)
{
	int a,b,c;
	
	char op;
	
	while(scanf("%d %c %d",&a,&op,&b) !=EOF && '?'!=op){
		
		if(op=='-'){
			c=a-b;
			printf("%d\n",c);
		}
		else if(op=='+'){
			c=a+b;
			printf("%d\n",c);
		}
		else if(op=='*'){
			c=a*b;
			printf("%d",c);
		}
		else if(op=='/'){
			c=a/b;
			printf("%d",c);
		}
		else printf("できません\n");
	}
	
	return 0;
}