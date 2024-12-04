/*  ex7_1
    Y_Aizaki  */

#include <stdio.h>

typedef struct point
{
    int x_elem; // x座標
    int y_elem; // y座標
}point;

point shift_point(point pointP, point pointQ){
    point pointR;

    pointR.x_elem = pointQ.x_elem + (-1)*(pointQ.y_elem - pointP.y_elem);
    // qとrのx座標の差の大きさは、pとqのy座標の差の大きさに等しい
    pointR.y_elem = pointQ.y_elem + (pointQ.x_elem - pointP.x_elem);
    // qとrのy座標の差の大きさは、pとqのx座標の差の大きさに等しい

    return pointR;
}

int main(void){
    point pointA,pointB,pointC,pointD;
    scanf("%d%d%d%d", &A.x_elem, &A.y_elem, &B.x_elem, &B.y_elem);

    pointC = shift_point(pointA, pointB);
    pointD = shift_point(pointB, pointC);

    printf("%d %d %d %d\n", pointC.x_elem, pointC.y_elem, pointD.x_elem, pointD.y_elem);

    return 0;
}