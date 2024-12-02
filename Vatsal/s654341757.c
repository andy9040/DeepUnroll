#include <stdio.h>

int main() {
    int N, i, zero_num=0;
    scanf("%d", &N);

    long int a[N];
    for(i=0; i<N; i++) {
        scanf("%ld", &a[i]);
        if(a[i]==0) {
            zero_num += 1;
        }
    }

    // printf("%ld\n", a[0]);

    if(zero_num==N) {
        printf("Yes\n");
        return 0;
    }

    if(N%3) {
        printf("No\n");
        return 0;
    }

    long int b[3] = {-1, -1, -1};
    b[0] = a[0];

    if(zero_num!=0) {
        for(i=0; i<N; i++) {
            if(a[i]!=0) {
                b[0] = a[i];
                break;
            }
        }
        b[1] = 0;
    }

    if(b[1]==-1) {
        for(i=0; i<N; i++) {
            if(b[0]!=a[i]) {
                b[1] = a[i];
                break;
            }
        }
    }


    for(i=1; i<N; i++) {
        if((b[0]!=a[i])&&(b[1]!=a[i])&&((b[0]^b[1])==a[i])) {
            b[2] = a[i];
            if(N==3) {
                printf("Yes\n");
                return 0;
            }
            break;
        }
    }

    if(((b[1]==-1) || (b[2]==-1)) && (zero_num==0)) {
        printf("No\n");
        return 0;
    }


    int count, j, flag=0;

    if(zero_num != 0) {
        if(b[2]==-1) {
            b[2] = b[0];

            j = 0;
            count = 0;
            for(i=0; i<N; i++) {
                if(b[j]==a[i]) {
                    count += 1;
                }
            }
            if(count==2*(N/3)) {
                if(b[0] == 0) {
                    printf("No\n");
                    return 0;
                } else {
                    flag = 3;
                }
            } else {
                flag = -1;
            }

        } else {
            for(j=0; j<3; j++) {
                count = 0;
                for(i=0; i<N; i++) {
                    if(b[j]==a[i]) {
                        count += 1;
                    }
                }
                if(count==(N/3)) {
                    flag += 1;
                } else {
                    flag = -1;
                    break;
                }
            }
        }
    } else {
        for(j=0; j<3; j++) {
            count = 0;
            for(i=0; i<N; i++) {
                if(b[j]==a[i]) {
                    count += 1;
                }
            }
            if(count==(N/3)) {
                flag += 1;
            } else {
                flag = -1;
                break;
            }
        }
    }


    

    if(flag == 3) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }



    return 0;

}