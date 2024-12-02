#include <stdio.h>

int main(){
   int i,j,l,m,n,k,a[200000],b[200000];

   scanf("%d %ld",&n,&k);
   for (i=0;i<n;i++) scanf("%d",&a[i]);
   while (k>0) {
      for (i=0;i<n;i++) b[i]=0;
      for (m=i=0;i<n;i++) {
         if (a[i]==n) {
            m++;
            continue;
         }
         j=i-a[i];
         if (j<0) j=0;
         l=i+a[i];
         if (l>=n) l=n-1;
         for (;j<=l;j++) b[j]++;
      }
      for (i=0;i<n;i++) a[i]=b[i]+m;
      if (m==n) break;
      k--;
   }
   printf("%d",a[0]);
   for (i=1;i<n;i++) printf(" %d",a[i]);
   puts("");
   return 0;
}
