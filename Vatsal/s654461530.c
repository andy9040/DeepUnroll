#include<stdio.h>
int main(void){

    int x,y,ans;

        char op;

        scanf("%d %c %d",&x,&op,&y);

            if(op=='+'){

                ans=x+y;

            }else if(op=='-'){

                ans=x-y;

            }else if(op=='*'){

                ans=x*y;

            }else if(op=='/'){

                ans=x/y;

            }else if(op=='?'){

                return 0;

}

printf("%d\n",ans);

return 0;

}