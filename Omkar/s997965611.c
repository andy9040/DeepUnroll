main(){
int t,n,m;
for(scanf("%d",&t);t--;){
scanf("%d%d",&n,&m);
if(n*m<0)printf("%d\n",__builtin_popcount(-n)+__builtin_popcount(m));
else printf("%d\n",__builtin_popcount(m-n));
}
exit(0);
}