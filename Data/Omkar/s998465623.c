    char b[11];
    int cnt,max;
    max=cnt=0;
    scanf("%s",b);
    for(int i=0;i<10;i++){
        if(b[i]=='A'||b[i]=='C'||b[i]=='G'||b[i]=='T'){
            cnt++;
        }
        else{
            if(max<cnt)max=cnt;
            cnt=0;
        }
    }
    printf("%d\n",max);
    return 0;
}