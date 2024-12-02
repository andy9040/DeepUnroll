main(){int a,b,c,e,d=0,i;scanf("%d%d%d",&a,&b,&c); 
for(i=0;i<a-1;i++){scanf("%d",&e);d+=e;}
if(a*c-d>0&&a*c-d<b)printf("%d",a*c-d);else puts(d>=a*c?"0":"-1");}

