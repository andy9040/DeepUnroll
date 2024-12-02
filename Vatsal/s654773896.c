# include <stdio.h>
int n,q;
int c[20];
 int sum(int a,int m,int i);
  int max(int v,int y);
int main()
{

	int b[200];
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d",&c[i]);
	scanf("%d",&q);
	for(int i = 0; i < q; i++)
		scanf("%d",&b[i]);
	for(int i = 0; i < q; i++)
	{
		int v;
		v = sum(b[i],0,0);
		if(v == 1)printf("yes\n");
		else printf("no\n");
    } 
}
 
 int sum(int a,int m,int i)
 {
 	if(m==a)	return  1;
 	else if(m<a&&i<=n-1){
			return max(sum(a,m,i+1),sum(a,m+c[i],i+1));
	 }
	 else return 0;
 }
 
 int max(int v,int y)
 {
 	if (v>y) return v;
 	else return y;
 }
