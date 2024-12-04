#include<stdio.h>
#include<math.h>
int main()
{
          int T,A[1000],i,j,k;
          double m,Tot=0,a=0,ans1,ans;
         while(1){
                    scanf("%d",&T);
         if(T==0)
         {
                   return 0;
         }
          for(j=0;j<T;j++)
          {
                    scanf("%d",&A[j]);
          }
          for(i=0;i<T;i++)
          {
                    Tot=Tot+A[i];
          }
          m=Tot/T;
          for(i=0;i<T;i++)
          {
                    a=a+((A[i]-m)*(A[i]-m));
          }
          ans1=a/T;
          ans=sqrt(ans1);
          printf("%.8lf\n",ans);
          ans=0;
          ans1=0;
          Tot=0;
          m=0;
          a=0;
         }

          return 0;

}

