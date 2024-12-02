#include<stdio.h>
#include<stdbool.h>

int main()
{
   int x,z,c=0;
   scanf("%d",&x);
   for(int i=0;i<3;i++){
    z = x%10;
    if(z == 1){
        c++;
    }
    x/=10;
}
printf("%d",c);
}
