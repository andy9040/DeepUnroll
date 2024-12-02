#include<stdio.h>
int main()
{
  int a, b, i;
  scanf("%d %d", &a, &b);
  char s[a+b+2];
  scanf("%s", s);
  for(i=0;i<a;i++)/*aまで*/{
    if(s[i]=='-'){
      printf("No\n");
      break;
    }else{}
    for(i=a+1;i<a+b+1;i++)/*a+1から*/{
      if(s[i]=='-'){
        printf("No\n");
        break;
      }else{}
    }
    if(s[a]=='-'){
      printf("Yes\n");
      break;
    }else{
      printf("No\n");
      break;
    }
  }
  return 0;
}
