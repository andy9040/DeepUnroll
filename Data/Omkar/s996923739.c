#include <stdio.h>
#include <string.h>

int main() {
    int length, j, count1=0, count2=0;
    char input[100000], endstr[1];

    scanf("%s", input);
    // printf("%s\n", input);

    for(length=0; input[length]!='\0'; ++length);
    // printf("%d\n", length);

    char restr1[length], restr2[length];

    endstr[0] = '1';

    for(j=0; j<length; j++) {
        if(endstr[0]=='1') {
            restr1[j] = '0';
            endstr[0] = '0';
        } else {
            restr1[j] = '1';
            endstr[0] = '1';
        }
    }

    endstr[0] = '0';

    for(j=0; j<length; j++) {
        if(endstr[0]=='1') {
            restr2[j] = '0';
            endstr[0] = '0';
        } else {
            restr2[j] = '1';
            endstr[0] = '1';
        }
    }

    // printf("%s\n%s\n", restr1, restr2);

    for(j=0; j<length; j++) {
        if(restr1[j]!=input[j]) {
            count1 += 1;
        }
        if(restr2[j]!=input[j]) {
            count2 += 1;
        }
    }

    if(count1 < count2) {
        printf("%d\n", count1);
    } else {
        printf("%d\n", count2);
    }

    return 0;
}