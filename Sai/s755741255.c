main(a,b,c){scanf("%d%d%d",&a,&b,&c);double s=a*b*sin(c*3.1416/180)/2;
printf("%lf\n%lf\n%lf\n",s,a+b+sqrt(a*a+b*b-2*a*b*cos(c*3.1416/180)),2*s/a);exit(0);}