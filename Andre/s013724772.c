/*ex4_1
ryo_1129*/
#include<stdio.h>

int main(void){
    int D,N,view,people;//変数宣言
    scanf("%d %d",&N,&D);//入力
    view = 2*D+1;//一人が見れる木の数
    //見る木に被りがない場合、
    if(N%view==0){
        people = N/view;
    //見る木に被りがある場合一人以外被りがないようにして１を足すのが最小人数
    }else{
        people = N/view+1;
    }
    //出力
    printf("%d\n",people);
    return 0;
}