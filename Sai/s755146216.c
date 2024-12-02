#include <stdio.h>

typedef enum {false, true} bool;


int main(void)
{
    int N;
    bool flag, ans;
    int a[3], ai;
    int a_num[3];
    char c;
    int i, j;
    int ctr;
    
    
    ans = true;
    
    a_num[0] = a_num[1] = a_num[2] = 0;
    ctr = 0;
    
    
    scanf("%d%c", &N, &c);
    
    
    for(i=0; i<N; i++)
    {
        scanf("%d%c", &ai, &c);
        
        
        flag = false;
        
        for(j=0; j<ctr; j++)
        {
            if(ai == a[j])
            {
                flag = true;
                
                a_num[j]++;
                
                break;
            }
        }
        
        if(!flag)
        {
            if(ctr < 3)
            {
                a[ctr] = ai;
                a_num[ctr++]++;
            }
            else
            {
                ans = false;
            
                break;
            }
        }
    }
    
    
    if(ans)
    {
        if(N%3)
        {
            if(a[0] == 0 && ctr == 1)
                ans = true;
            else
                ans = false;
        }
        else
        {
            if(a[0]^a[2] == a[1] && a[1]^a[0] == a[2])
            {
                if(a_num[0] == a_num[1] == a_num[2])
                    ans = true;
                else
                    ans = false;
            }
        }
    }
    
    
    if(ans)
        printf("Yes\n");
    else
        printf("No\n");
    
    
    //system("pause");
    
    return 0;
}
