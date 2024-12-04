#include <stdio.h>
#include <stdlib.h>

int main()
{
    char s;
    printf("please enter you day ");
    scanf("%c",&s);
    if( s=='SAT')
    {
        printf("the number of this day is 1");
        printf("it is saturday today and tomorrow will be sunday");
    }
    else if (s=='SUN')
    {
        printf("the number of this day is 2");
        printf("it is sunday today and tomorrow will be monday");
    }
    else if (s=='MON')
    {
        printf("the number of this day is 3");
        printf("it is monday today and tomorrow will be  tuesday");
    }
    else if (s=='TUE')
    {
        printf("the number of this day is 4");
        printf("it is tuesday today and tomorrow will be  wedday");
    }
    else if (s=='WED')
    {
        printf("the number of this day is 5");
        printf("it is wedensday today and tomorrow will be  thurathday");
    }
    else if (s=='THU')
    {
        printf("the number of this day is 6");
        printf("it is tuesday today and tomorrow will be  firday");
    }
    else if (s=='FRI')
    {
        printf("the number of this day is 7");
        printf("it is friday today and tomorrow will be  sunday");
    }





}






