#include <stdio.h>


int main()
{
int A,B,C,d;
scanf("%d %d %d",&A,&B,&C);


if (A&&B==5&&C==7)
    printf("YES\n");
else if (A&&C==5&&B==7)
    printf("YES\n");
else if(A==7&&B&&C==5)
    printf("YES\n");
else
printf("NO\n");

return 0;
}
