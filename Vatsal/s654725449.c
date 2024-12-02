#include <stdio.h>

int main(void)
{
int N,A,B;

scanf("%d %d %d", &N,&A,&B);

if (B>A)
printf("%d\n", N*A);
else
printf("%d\n", N*B);

return 0;
}