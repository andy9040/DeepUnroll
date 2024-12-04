#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define U1 unsigned char
#define S1 char
#define	S4 int
#define DU double

#define MAX_CITY_WIDTH          (100000)
#define MAX_CITY_HIGHT          (100000)

#define NOT_REACH               (0)

/* いもす法で使う */
#define ENTER                   (1)
#define EXIT                    (-1)

S4 main()
{
	//S4 s4_t_scanfRtn;
	U1 u1_t_delimiter;
	S4 s4_t_loopIndex;
	S4 s4_t_ix;
	S4 s4_t_iy;
	
	S4 s4_t_numBaseStation;
	S4 s4_t_cityWidth;
	S4 s4_t_cityHight;
	S4 s4_t_x;
	S4 s4_t_y;
	S4 s4_t_w;
	U1 u1_tp_isReachX[MAX_CITY_WIDTH + 1];
	U1 u1_tp_isReachY[MAX_CITY_HIGHT + 1];
	U1 u1_t_isReachWifiX;
	U1 u1_t_isReachWifiY;

	/* ある基地局の電波が届く範囲 */
	S4 s4_t_minX;
	S4 s4_t_maxX;
	S4 s4_t_minY;
	S4 s4_t_maxY;

	/* 初期化 */
	for (s4_t_ix = (S4)0; s4_t_ix <= (S4)MAX_CITY_WIDTH; s4_t_ix++)
	{
		u1_tp_isReachX[s4_t_ix] = (U1)NOT_REACH;
	}

	for (s4_t_iy = (S4)0; s4_t_iy <= (S4)MAX_CITY_HIGHT; s4_t_iy++)
	{
		u1_tp_isReachY[s4_t_iy] = (U1)NOT_REACH;
	}

	/* 入力 */
	//s4_t_scanfRtn = scanf("%d,%lf,%lf%c", &s4_t_studentNum, &du_t_weight, &du_t_height, &u1_t_delimiter);
	(void)scanf("%d %d %d%c", &s4_t_numBaseStation, &s4_t_cityWidth, &s4_t_cityHight, &u1_t_delimiter);
	
	/*wifi到達範囲の計算 */
	for (s4_t_loopIndex = (S4)0; s4_t_loopIndex < s4_t_numBaseStation; s4_t_loopIndex++)
	{
		(void)scanf("%d %d %d%c", &s4_t_x, &s4_t_y, &s4_t_w, &u1_t_delimiter);

		/* koto距離の性質上、x方向で届くならy方向の距離にかかわらず到達する。そのため、x方向・y方向独立で到達を判断すれば良い */
		/* x方向 */
		s4_t_minX = s4_t_x - s4_t_w;
		s4_t_maxX = s4_t_x + s4_t_w;
		/* 街の外から届く→いもす法の入口 */
		if (s4_t_minX < (S4)0)
		{
			s4_t_minX = (S4)0;
		}
		u1_tp_isReachX[s4_t_minX] += (U1)ENTER;
		/* 端まで到達→いもす法の出口は無い */
		if (s4_t_maxX > s4_t_cityWidth)
		{
			/* 何もしない */
		}
		else
		{
			u1_tp_isReachX[s4_t_maxX] += (U1)EXIT;
		}

		/* y方向 */
		s4_t_minY = s4_t_y - s4_t_w;
		s4_t_maxY = s4_t_y + s4_t_w;
		/* 街の外から届く→いもす法の入口 */
		if (s4_t_minY < (S4)0)
		{
			s4_t_minY = (S4)0;
		}
		u1_tp_isReachY[s4_t_minY] += (U1)ENTER;
		/* 端まで到達→いもす法の出口は無い */
		if (s4_t_maxY > (S4)s4_t_cityHight)
		{
			/* 何もしない */
		}
		else
		{
			u1_tp_isReachY[s4_t_maxY] += (U1)EXIT;
		}
	}

	/* 全ての地点にwifiが到達したか判定 */
	/* x方向・y方向いずれか全てで到達ならば全地点に到達 */
	u1_t_isReachWifiX = (U1)0;
	u1_t_isReachWifiY = (U1)0;
	for (s4_t_ix = (S4)0; s4_t_ix <= s4_t_cityWidth; s4_t_ix++)
	{
		u1_t_isReachWifiX += u1_tp_isReachX[s4_t_ix];
		/* 途中で入口の数＜出口の数となる→到達範囲が途絶えた */
		if (u1_t_isReachWifiX <= (U1)0)
		{
			break;
		}
	}

	for (s4_t_iy = (S4)0; s4_t_iy <= s4_t_cityHight; s4_t_iy++)
	{
		u1_t_isReachWifiY += u1_tp_isReachY[s4_t_iy];
		/* 途中で入口の数＜出口の数となる→到達範囲が途絶えた */
		if (u1_t_isReachWifiY <= (U1)0)
		{
			break;
		}
	}

	/* 結果を出力 */
	/* 全範囲を網羅している判定 */
	if ((s4_t_ix >= s4_t_cityWidth) ||
		(s4_t_iy >= s4_t_cityHight))
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	
	return((S4)0);
}

