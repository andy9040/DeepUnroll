#include <stdio.h>

typedef struct {
    int x,y,a;
} data;

int main()
{
    int w,h,n,maxmin[4] = {0,100,0,100};
    data data[100];
    int i,j;

    scanf("%d %d %d",&w,&h,&n);
    for (i = 0; i < n; i++)scanf("%d %d %d",&data[i].x,&data[i].y,&data[i].a);

    int ans = w * h;

    for (i = 0; i < n; i++)
    {
        switch (data[i].a)
        {
        case 1:
            if(maxmin[0] < data[i].x)maxmin[0] = data[i].x;
            break;
        case 2:
            if(maxmin[1] > data[i].x)maxmin[1] = data[i].x;
            break;
        case 3:
            if(maxmin[2] < data[i].y)maxmin[2] = data[i].y;
            break;
        default:
            if(maxmin[3] > data[i].y)maxmin[3] = data[i].y;
            break;
        }
    }
    if(maxmin[0] < maxmin[1] && maxmin[2] < maxmin[3])
    {
        printf("%d",(maxmin[1] - maxmin[0]) * (maxmin[3] - maxmin[2]));
    }
    else
    {
        printf("0");
    }
    
}