#include <stdio.h>
#include <math.h>

#define MAX 1000

int main(void)
{
    int i;

    while (1) {
        int n_students;
        scanf("%d", &n_students);

        if (n_students == 0) {
            break;
        } else {
            int points[MAX];
            for (i = 0; i < n_students; i++) {
                scanf(" %d", &points[i]);
            }

            double ave = 0;
            for (i = 0; i < n_students; i++) {
                ave += points[i];
            }
            ave /= n_students;

            double variance = 0;
            for (i = 0; i < n_students; i++) {
                variance += pow(points[i] - ave, 2);
            }
            variance /= n_students;

            double deviation = sqrt(variance);

            printf("%f\n", deviation);
        }
    }

    return 0;
}