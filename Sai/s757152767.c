#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#undef DBG

int main()
{
        int souwa;
        int  inputc;
        char numbuff[100000+1];
        long long int numbers[1000];
        int numnum;
        long long int i,j;
        long long int N, A, B, C, D;

        j = 0;

        numnum = 0;
        j = 0;
        while( (inputc = getc(stdin)) != EOF ) {
                if( inputc == ' ' || inputc == '\n' ) {
                        numbuff[j]  = '\0';
                        numbers[numnum++] = atoll(numbuff);
                        j=0;
                        continue;
                }
                else {
                        numbuff[j++] = inputc;
                }
        }

        N = numbers[0];
        A = numbers[1];
        B = numbers[2];
#ifdef DBG
        printf("%lld\n", LLONG_MAX );
        printf("N=%lld A=%lld B=%lld \n", N, A, B );
#endif

        int densha, tax;
        densha = N*A;
        if( N*A >= B ) {
                printf("%lld\n", B);
        } else {
                printf("%lld\n", N*A);
        }


        return 0;

}
