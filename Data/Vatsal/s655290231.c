#include<stdio.h>
int main(){
  char s[100000];
  int i,count;
  scanf("%s",s);
  
    if(s[0]=='1'){
      for(i=1;i<100000;i++){
        if(i%2==0&&s[i]=='0'){
          count++;
        }
        if(i%2==1&&s[i]=='1'){
          count++;
        }
        if(s[i]=='\0')break;
      }  
    }
       if(s[0]=='0'){
      for(i=1;i<100000;i++){
        if(i%2==0&&s[i]=='0'){
          count++;
        }
       if(i%2==1&&s[i]=='1'){
          count++;
       }
        if(s[i]=='\0')break;
      }
       }
  printf("%d",count);
  return 0;
}