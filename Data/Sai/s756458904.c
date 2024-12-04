 #include<stdio.h>
 int main(void)
 {
     int n,p[20],i,j=0;

     scanf("%d",&n);

     for(i=0;i<n;i++)
       scanf("%d",&p[i]);

     for(i=1;i<n-1;i++){
       if((p[i]>p[i-1])&&(p[i]<p[i+1]))
          j++;
       else if((p[i]>p[i+1])&&(p[i]<p[i-1]))
          j++;
     }
       printf("%d\n",j);

       return 0;
 }
