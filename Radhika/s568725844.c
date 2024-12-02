#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#define BUFSIZE 1000000

int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int main(void){
int N;
  scanf("%d",&N );
 for(int i = 1;;i++){
   if(1000*i  > N){
     printf("%d",1000*(i) - N);
     exit(0);
   }
 }


/*
  qsort(a, n, sizeof(int), compare_int);
*/
}
