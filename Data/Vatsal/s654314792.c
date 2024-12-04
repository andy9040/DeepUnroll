#include <stdio.h>

int main()
{
    int i;
    int a[100];
    for(i=0;;i++){
        scanf("%d",a+i);
        if(*(a+i) == 0){
            break;
        }
    }
    for(i=0;*(a+i)!=0;i++){
        printf("Case %d: %d\n",i+1,*(a+i));
    }
    return 0;
}