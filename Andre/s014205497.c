#include <stdio.h>
int main (void){
char a[3],b[3];
scanf("%s",a);
scanf("%s",b);

if (a[0]==b[2]&&a[1]==b[1]&&a[2]==b[0]){
    printf("Yes");
}else{
    printf("No");
}
return 0;
}
