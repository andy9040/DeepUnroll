#include <stdio.h>

int main()
{
    /* ここから */
    int N;
    int otsuri;
    scanf("%d",&N);
    otsuri=(N/1000+1)*1000-N;
    if(otsuri>=1000) otsuri=0;
    printf("%d\n",otsuri);
    /* ここまで */
    return 0;
}