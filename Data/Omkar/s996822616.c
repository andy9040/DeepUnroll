#include<stdio.h>
int i,j,k,l,count,b,d=0,n=0,num[2000000];
void output(void);
void F(void);
void L(void);
void calc(void);
int main(void){
  scanf("%d",&n);
  char order[12];
  for(i=0;i<n;i++){
    scanf("%s %d",order,&b);
    switch(order[0]){
        case 'i':
            num[i]=b;
        break;
        case 'd':
            if(order[6]=='F'){
                F();
            }else if(order[6]=='L') {
                L();
            }else {
                calc();
            }
        break;
    }
  }
  output();
  return 0;
}
void F(void){
    i-=2;
    n-=2;
}
void L(void){
    i--;
    n--;
    d++;
}
void calc(void){
    i--;
    n--;
    l=0;
    for(j=i;j>=0;j--){
        if(l>0)break;
        if(b==num[j]){
            k=i-j;
            count=0;
            l++;
            while(k!=count++){
                num[j+count-l]=num[j+count];
            }
            i--;
            n--;
        }
    }
}
void output(void){
   for(i=0;i<n-d;i++){
    if(i==n-d-1){
      printf("%d\n",num[n-1-i]);
    }else{
      printf("%d ",num[n-1-i]);
    }
  } 
}
