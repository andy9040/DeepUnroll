A,B;main(a,b){scanf("%d%d",&a,&b);
A=(a+11)%13;B=(b+11)%13;
if(a==10)puts(A<B?"Bob":A>B?"Alice":"Draw");
}