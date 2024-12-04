#inlcude <stdio.h>
int main ()
{
        int a, b, uncovered_part;
        scanf ("%d %d", &a, &b);
        uncovered_part = a - (2 * b);
        if (uncovered_part < 0) {
                   printf("%d", 0);
        }
        else {
                    printf("%d\n", uncovered_part);
       }
       return 0;
}