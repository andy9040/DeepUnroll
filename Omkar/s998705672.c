#include<stdio.h>
#include<stdlib.h>

#define NEW(p,n){p=malloc((n)*sizeof(p[0]));if(p==NULL){printf("not enough memory\n");exit(1);};}
//pの型の変数n個の要素分のメモリを確保し、そのアドレスをpに代入するマクロ

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

//S[0]から始まる文字列の長さを求める関数
int string_len(char* str){
    int len=0;
    while(str[len]!=0){
        len++;
    }
    return len;
}

//753数なら1,そうでないなら0
int judge_753(int N){
    //int型Nを、文字列char配列に変換
    char s[10]={'\0'};
    snprintf(s,10,"%d",N);

    //Nの桁数
    int digit=string_len(s);

    int count=0;
    for(int i=0;i<digit;i++){
        if(s[i]=='3'){
            count++;
            break;
        }
    }
    for(int i=0;i<digit;i++){
        if(s[i]=='5'){
            count++;
            break;
        }
    }
    for(int i=0;i<digit;i++){
        if(s[i]=='7'){
            count++;
            break;
        }
    }

    if(count==3) return 1;
    else return 0;
}

int count_753(int s,int N, int ans,int a, int b, int c){
    if(s>N) return ans;

    if(a+b+c==3) ans++;

    count_753((s*10+3),N,ans,1,b,c);
    count_753((s*10+5),N,ans,a,1,c);
    count_753((s*10+7),N,ans,a,b,1);
}

int main(void){
    int N;
    scanf("%d",&N);

    int ans=0;
    ans+=count_753(0,N,ans,0,0,0);

    printf("%d\n",ans);

    return 0;
}