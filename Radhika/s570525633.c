#include <stdio.h>
#include <math.h>

//定数πの定義
#define PI 3.14159265359

int main(void)
{
	//dist_a、dist_b、dist_cは各辺の長さ
	double dist_a, dist_b, dist_c;
	//angle_cは角Cの角度(度)、rad_cは角Cの角度(ラジアン)
	double angle_c, rad_c;
	//areaは面積を、circuitは周の長さを、heightは三角形の高さを格納
	double area, circuit, height;

	//辺a、辺b、角Cを入力
	scanf("%lf %lf %lf", &dist_a, &dist_b, &angle_c);
	//角Cの値をラジアンに変換
	rad_c = PI * angle_c / 180;

	//面積を求め、結果を出力
	area = dist_a * dist_b * sin(rad_c) / 2;
	printf("%lf\n", area);

	//余弦定理を利用し辺cの長さを求め、周の長さを出力する
	dist_c = sqrt(pow(dist_a, 2.0) + pow(dist_b, 2.0) - (2 * dist_a * dist_b) * cos(rad_c));
	circuit = dist_a + dist_b + dist_c;
	printf("%lf\n", circuit);

	/*
	底辺をdist_a、高さをheight、面積をareaとすると
	dist_a * height / 2 = area
	height = 2 * area / dist_a
	*/
	height = 2 * area / dist_a;
	printf("%lf\n", height);

	return 0;
}
