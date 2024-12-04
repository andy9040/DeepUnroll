#include <stdio.h>

long int F_func(long int a, long int b) {
    long int c=0;
    if(a>b) {
        while(a) {
            c += 1;
            a /= 10;
        }
    } else {
        while(b) {
            c += 1;
            b /= 10;
        }
    }
    return c;
}

int main() {
    long int n;
    scanf("%ld", &n);

    long int flag=1, tmp, min=100;
    while(n>=flag*flag) {
        if(n%flag==0) {
            tmp = F_func(flag, n/flag);
            if(min>tmp) {
                min = tmp;
            }
        }
        flag++;
    }

    printf("%ld\n", min);

    return 0;

}