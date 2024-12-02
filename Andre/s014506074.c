#include<stdio.h>
int main()
{
    int i;
    char s[3];
  	int ans = 0;
  	for(i=0;i<3;i++){
      scanf("%d", &s[i]);
      if(s[i] == 1){
          ans++;
      }
    }
	printf("%d",ans);    
    return 0;
}