#define _CRT_SECURE_NO_WARNINGS
//#define _USE_MATH_DEFINES
#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//#include<string.h>
#define P(type,x) fprintf(stdout,"%"#type"\n",x)
int main() {
	int n, i,max,num,d,dd,t;
	for (; fscanf(stdin, "%d", &n), n != 0;fprintf(stdout,"%d %d\n",num,max)) {
		num=max=-1;
		fscanf(stdin, "%d%d%d", &t, &d, &dd);
		max = d + dd,num=t;
		for (i = 1; i < n; i++) {
			fscanf(stdin, "%d%d%d", &t, &d, &dd);
			if (d + dd > max)max = d + dd, num = t;
		}
	}
	return 0;
}