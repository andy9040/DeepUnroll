// ヘッダファイルのインクルード
#include<stdio.h>
#include<math.h>

// マクロ定義
#define X 0
#define Y 1
#define X_AND_Y 2
#define NORTH 90 //度表現

#define compile 0 //デバッグ用

// 関数のプロトタイプ宣言
double func_cal_rad(double angle); //度からラジアンへ変換する関数
double func_cal_x(int edge, double angle_r, double x); //x座標を計算する関数
double func_cal_y(int edge, double angle_r, double y); //y座標を計算する関数
void func_output(double array[], int n); //結果の出力を行う関数

main()
{
	int input_l = 0, input_t = 0; //入力代入用の変数,input_l:進む距離,input_t:回転する角度
	double turn = 0; //回転角代入用の変数,turn:現在の回転角
	double t_rad = 0; //回転角代入用の変数,t_rad:回転角を[rad]に変換
	double point[X_AND_Y] = {0, 0}; //座標代入用の変数
	
	turn = NORTH; //問題の仕様では最初の角度はx軸に対して垂直(角度は90°)になる
	
	scanf("%d,%d", &input_l, &input_t); //入力の取得
	
	while((0 != input_l) && (0 != input_t)) //input_l,input_tの2値が0でないとき
	{
		t_rad = func_cal_rad(turn); //度表記をラジアン表記に変換
		point[X] = func_cal_x(input_l, t_rad, point[X]); //x座標の計算
		point[Y] = func_cal_y(input_l, t_rad, point[Y]); //y座標の計算
		
#if compile == 1 //デバッグ用
		printf("point[X] = %.0lf point[Y] = %.0lf\n", point[X], point[Y]);
#endif
		
		turn -= input_t; //現在の角度の値input_tをturnに代入
		input_l = 0, input_t = 0; //入力前に一度初期化する
		scanf("%d,%d", &input_l, &input_t); //入力の取得
	}
	func_output(point, X_AND_Y); //原点からの距離を計算
	
	return 0;
}
double func_cal_rad(double angle_d) //度からラジアンへ変換する関数
{
	double rad = 0;
	rad = (angle_d * M_PI) / 180; //角の変換公式を使用,要インクルードmath.h
	return rad;
}
double func_cal_x(int edge, double angle_r, double x) //x座標を計算する関数
{
	double p_x = 0;
	p_x = (double)(edge * cos(angle_r)) + x; //移動先の座標から移動元の座標を引いた長さが移動先のx座標,要インクルードmath.h
	return p_x;
}
double func_cal_y(int edge, double angle_r, double y) //y座標を計算する関数
{
	double p_y = 0;
	p_y = (double)(edge * sin(angle_r)) + y; //移動先の座標から移動元の座標を引いた長さが移動先のy座標,要インクルードmath.h
	return p_y;
}
void func_output(double array[], int n) //結果の出力を行う関数
{
	int i = 0;
	for(i = 0; i < n; i++) //出力をループさせる
	{
		if(array[i] > 0) //array[i]の要素が正の実数の場合
		{
			array[i] = floor(array[i]); //小数点以下切り上げを行う,要インクルードmath.h
		}
		else
		{
			array[i] = ceil(array[i]); //小数点以下切り上げを行う,要インクルードmath.h
		}
		printf("%.0lf\n", array[i]); //1回目のループでx座標,2回目のループでy座標をそれぞれ表示
	}
}