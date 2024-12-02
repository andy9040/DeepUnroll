/*
 * ex7-1
 * kamecha
 */
#include<stdio.h>

typedef struct point{
    int x_elem;
    int y_elem;
}point;

//構造体の足し算
point add(point a, point b){
    point tmp = {0, 0};
    tmp.x_elem = a.x_elem + b.x_elem;
    tmp.y_elem = a.y_elem + b.y_elem;
    return tmp;
}

point dec(point a, point b){
    point tmp = {0, 0};
    tmp.x_elem = a.x_elem - b.x_elem;
    tmp.y_elem = a.y_elem - b.y_elem;
    return tmp;
}

//頂点を原点から90度反時計回りに(正方形の形に沿って)シフト
point shift_point(point ptr){
    point vec = {-ptr.y_elem, ptr.x_elem};
    return add(vec, ptr);
}

int main(void){
    point p1, p2, p3, p4;
    scanf("%d", &p1.x_elem);
    scanf("%d", &p1.y_elem);
    scanf("%d", &p2.x_elem);
    scanf("%d", &p2.y_elem);
    p3 = add(p1, shift_point(dec(p2, p1)));
    p4 = add(p2, shift_point(dec(p3, p2)));
    printf("%d %d %d %d\n", p3.x_elem, p3.y_elem, p4.x_elem, p4.y_elem);
    return 0;
}
