/* ex 7_1
   offNaria */

#include <stdio.h>

typedef struct point
{
    int x_elem;
    int y_elem;
} point;

//b-aベクトルをaを中心として反時計まわりに90度回転し，始点をbにしたものの終点を計算する関数
point shift_point(point a, point b);

int main(void)
{
    point p_1, p_2, p_3, p_4;
    scanf("%d %d %d %d", &p_1.x_elem, &p_1.y_elem, &p_2.x_elem, &p_2.y_elem);
    p_3 = shift_point(p_1, p_2); //p_2-p_1ベクトルをp_1を中心として反時計回りに90度回転し，始点をp_2としたベクトルの終点がp_3
    p_4 = shift_point(p_2, p_3); //p_3-p_2ベクトルをp_2を中心として反時計回りに90度回転し，始点をp_3としたベクトルの終点がp_4
    printf("%d %d %d %d\n", p_3.x_elem, p_3.y_elem, p_4.x_elem, p_4.y_elem);
    return 0;
}

point shift_point(point a, point b)
{
    point rotatedVec = {b.x_elem + (a.y_elem - b.y_elem), b.y_elem + (b.x_elem - a.x_elem)};
    return rotatedVec;
}