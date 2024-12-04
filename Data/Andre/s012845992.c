int main()
{
    char w[1000] ={0};
    char t[1000] ={0};
    int count=0;
    int i=0;

    scanf("%s",w);

    do {
        scanf("%s",t);
        for(i=0; i<=MAX; i++){
            if(strcmp(t,"END_OF_TEXT") == 0){
                break;
            }
            if(t[i] >= 65 && t[i] <= 90){
                t[i] = t[i] + 32;
            }
        }
        if(strcmp(t,"END_OF_TEXT") == 0){
            break;
        }
        if(strcmp(w,t) == 0){
            count++;
        }
        i++;
    } while (strcmp(t,"END_OF_TEXT") != 0);
    printf("%d",count);
    return 0;
}