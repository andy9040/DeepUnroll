 #include <stdio.h>
     
    int main (void)
    {
      char s[3];
      int i;
      int cnt;
      
      scanf("%s",s);
      
     	for (i=0;i<3;i++)
        {if (s[i] == '1')
          cnt++;
        } 
   printf("%d",cnt);
	return 0;
}