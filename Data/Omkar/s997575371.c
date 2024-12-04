#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, const char * argv[]) {
   
    
    int N;
    scanf("%d\n",&N);
    
    int *a;
    
    a=(int *)malloc(N+1);
  
    char *buff;
    
    buff=(char *)malloc(N*2+1);
    
    gets(buff);
    
    char str2[256] = " ";
    strcat(buff,str2);
    int nn=1;
    for (int i=1; i<=N*2+1; i++)
    {
        if (buff[i]==' ')
        {
            a[nn]=atoi(&buff[i-1]);
            nn++;

        }
        
        
    }
    
    int likesum=0;
    
    for (int i=1; i<=N; i++) {
        
        // printf("  %d    %d \n",a[i],a[a[i]]);
        
        if (i==a[a[i]]) {
            likesum++;
            //printf("\na");
        }
        
        
    }
    
    
    printf("%d\n",likesum/2);
    
    
    return 0;
}
