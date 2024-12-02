#include<stdio.h>
#include<string.h>
int main()
{
  int n,t,i=0;
  scanf("%d",&n);
  char s[100];
  scanf("%s",&s);
  t=strlen(s);
  if(t<=n)
  {
    printf("%s",s);
  }
  else
  {
    while(t>0)
    {
      printf("%c",s[i]);
      t--;
      i++;
    }
  }
}
      
    
  
  
  
