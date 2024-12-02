#include <stdio.h>
 
int main()
{
 
  /* 文字 */
  char moji[1];
  char str[27] = "abcdefghijklmnopqrstuvwxyz";
 
  scanf("%c", moji);
  
  int i=0;
  
  for(i=0;i<27;i++){
		if(moji[0] == str[i] ){
  printf("%c", str[i+1]);
        }
  }
  
 
  return 0;
}
