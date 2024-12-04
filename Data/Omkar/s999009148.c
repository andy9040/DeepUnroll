#include<stdio.h>
void rsort(int n[], int s){

    int i,j,tmp;
    for(i=0;i<s;i++){
        for(j=i+1;j<s;j++){
            if(n[i]<n[j]){
               tmp = n[i];
               n[i] = n[j];
               n[j] = tmp;
            }
        }
    }
}
int main()
{
    int x,y,a,b,c,i;
    scanf("%d %d %d %d %d", &x,&y,&a,&b,&c);
    int p[a],q[b],r[c],res[a+b+c];
    for(i=0;i<a;i++){
        scanf("%d", &p[i]);
    }
    for(i=0;i<b;i++){
        scanf("%d", &q[i]);
    }
    for(i=0;i<c;i++){
        scanf("%d", &r[i]);
    }
    rsort(p,a);
    rsort(q,b);
    rsort(r,c);

    for(i=0;i<x+y+c;i++){
        if(i<x){
            res[i] = p[i];
        }
        else if(i-x<y){
            res[i] = q[i-x];
        }
        else if(i-x-y<x+y+c){
            res[i] = r[i-x-y];
        }
    }
    rsort(res,x+y+c);
    int sum=0;
    for(i=0;i<x+y;i++){
        sum+= res[i];
    }

    printf("%d\n", sum);

    return 0;
}
