main(){
int t,n,m,l;
for(scanf("%d",&t);t--;){
scanf("%d%d",&n,&m);
if(n*m<0)printf("%d\n",__builtin_popcount(-n)+__builtin_popcount(m));
else{if(n<0)l=n,n=-m,m=-l;printf("%d\n",__builtin_popcount(n^m));}
}
exit(0);
}