/* ex7_1
   UMAboogie */

#include<stdio.h>

//座標用の構造体を宣言
typedef struct point{
    int x_elem;
    int y_elem;
}point;

//座標をずらす関数を定義
point shift_point(point a, int x, int y){
  point b;
  b.x_elem = a.x_elem + x;
  b.y_elem = a.y_elem + y;
  return b;
}


int main(void){
  point vertex_1,vertex_2,vertex_3,vertex_4;
  int x_gap,y_gap;
  //2点の座標を入力
  scanf("%d %d %d %d", &vertex_1.x_elem, &vertex_1.y_elem, &vertex_2.x_elem, &vertex_2.y_elem);
  //2点がx方向、y方向にどれだけずれているかを計算し、それぞれx_gap,y_gapに代入
  x_gap = vertex_2.x_elem - vertex_1.x_elem;
  y_gap = vertex_2.y_elem - vertex_1.y_elem;

  //3点目は2点目をx方向に-y_gap,y方向にx_gapずらした点
  vertex_3 = shift_point(vertex_2, -y_gap, x_gap);
  //4点目は1点目をx方向に-y_gap,y方向にx_gapずらした点
  vertex_4 = shift_point(vertex_1, -y_gap, x_gap);

  //答えを入力
  printf("%d %d %d %d", vertex_3.x_elem, vertex_3.y_elem, vertex_4.x_elem, vertex_4.y_elem);

  return 0;
}
