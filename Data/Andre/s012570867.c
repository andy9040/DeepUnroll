#include<stdio.h>
    int main(void){

        int a,b;

        char op;

            while(1){

                scanf("%d %c %d",&a,&op,&b);

                    if(op=='+'){
                        a=a+b;
                        printf("%d\n",a);

                    }else if(op=='-'){
                        a=a-b;
                        printf("%d\n",a);

                    }else if(op=='*'){
                        a=a*b;
                        printf("%d\n",a);

                    }else if(op=='/'){
                        a=a/b;
                        printf("%d\n",a);

                    }else{

                        return 0;

                    }



            }

    }