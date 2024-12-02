#include <stdio.h>

int main()
{
    int num;
    int l, r;
    int roop;
  	int i;

    scanf("%d", &roop);
//    printf("num:%d \n",roop);
    num = 0;
    for (i = 1; i <= roop; i++)
    {
        scanf("%d %d", &l, &r);
        num += r - l + 1;
    }
    printf("%d",num);
    return 0;
}