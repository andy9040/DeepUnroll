main(){double a,b,c,d,e,f,g;for(scanf("%*d");~scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f);puts(d>c+f?"0":c>d+f?"2":f>c+d?"-2":"1"))d=hypot(a-d,b-e);}