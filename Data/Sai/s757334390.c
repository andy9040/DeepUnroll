/* ex7_1
saitomo*/
#include<stdio.h>



//頂点を表す構造体point を定義
typedef struct point{
    int x_elem;
    int y_elem;
}point;
//プロトタイプ宣言
point shift_point(point vec1,point vec2);

int main(void){
    point vec1,vec2,vec3,vec4;
    scanf("%d%d%d%d",&vec1.x_elem,&vec1.y_elem,&vec2.x_elem,&vec2.y_elem);
    vec3=shift_point(vec1,vec2);
    vec4=shift_point(vec2,vec3);
    printf("%d %d %d %d\n",vec3.x_elem,vec3.y_elem,vec4.x_elem,vec4.y_elem);
    return 0;
}

//点を移動させる関数を定義
point shift_point(point vec1,point vec2){
    point new_vec;
    new_vec.x_elem=vec2.x_elem-vec1.x_elem;//とりあえず計算に使う値を代入しておく
    new_vec.y_elem=vec2.y_elem-vec1.y_elem;
    new_vec.y_elem=new_vec.x_elem+vec2.y_elem;
    new_vec.x_elem=vec2.x_elem-(new_vec.y_elem-new_vec.x_elem-vec1.y_elem);
    //図を描くことで計算式を求めた
    return new_vec;//ポイントとして出力
}
