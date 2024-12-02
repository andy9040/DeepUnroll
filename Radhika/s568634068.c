#include <stdio.h>
#include <math.h>

int min = 100000;

void DIV6(int, int);

void DIV9(int N, int num)  
{
    int R = 0, times = 0;
    
    if(N < 9)
        DIV6(N, num);
    else
    {
        while(N >= 9)
        {
            R += pow(9, times)*(N%9);
            N /= 9;
            times++;
        }
        DIV9(R, num+N);
        DIV6(R, num+N);
    }
}
void DIV6(int N, int num)   
{
    int R = 0, times = 0;
  
    if(N < 6)
    {
        if(min > num+N)
            min = num+N;
    }
    else
    {    
        while(N >= 6)
        {
            R += pow(6, times)*(N%6);
            N /= 6;
            times++;
        }
        DIV9(R, num+N);
        DIV6(R, num+N);
    }
}

int main(void)
{
    int N;
  
    scanf("%d", &N);
    
    DIV9(N, 0);
    DIV6(N, 0);
    
    printf("%d\n", min);

    system("pause");
    return 0;
}
