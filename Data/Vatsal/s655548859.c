A,B;main(a,b){scanf("%d%d",&a,&b);
A=(a+11)%13;B=(b+11)%13;
if(b==13)puts(A<B?"Bob":A>B?"Alice":"Draw");
}