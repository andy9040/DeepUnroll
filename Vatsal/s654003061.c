//
//  main.c
//  Organize Your Train part II
//
//  Created by x15071xx on 2016/06/07.
//  Copyright ?? 2016??´ AIT. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <math.h>
int check(char sr[500][73],char tmp[73],int sr_count){
    
    int i,b=0;
    
    for (i=0; i<sr_count; i++) {

        if (strcmp(sr[i],tmp)==0) {
            break;
        }
    }
    
    if (i == sr_count) {
        for (i=0; i < strlen(tmp); i++) {
            sr[sr_count][i] = tmp[i];
        }
        b=1;
        return b;
    }
    
    return b;
}

int main(int argc, const char * argv[]) {
    
    int i,mm;
    
    scanf("%d",&mm);
    for (i=0; i<mm; i++) {
        char a[73]={0},s[72]={0},r[72]={0},sr[500][73]={0},tmp[73]={0};
        int j,k,l,m,len,n,count_r=0,count_s=0,sr_count=0;
        
        scanf("%s",a);
        len = strlen(a);
        
        for (j=0; j<len-1; j++) {
            
            for (k=0; k<=j; k++) {
                s[k] = a[k];
                count_s++;
            }
            
            for (l=0; l<len-j-1; l++) {
                r[l] = a[j+1 + l];
                count_r++;
            }
            
            //sr
            for (m=0; m<count_s; m++) {
                tmp[m] = s[m];
            }
            
            for (n=0; n<count_r; n++) {
                tmp[count_s + n] = r[n];
            }
            
            sr_count +=check(sr, tmp, sr_count);
            //rs
            
            for (m=0; m<count_r; m++) {
                tmp[m] = r[m];
            }
            
            for (n=0; n<count_s; n++) {
                tmp[count_r + n] = s[n];
            }

            sr_count +=check(sr, tmp, sr_count);
            
            //Sr
            for (m=0; m<count_s; m++) {
                tmp[m] = s[count_s - 1 - m];
            }
            
            for (n=0; n<count_r; n++) {
                tmp[count_s + n] = r[n];
            }
            
            sr_count +=check(sr, tmp, sr_count);
            //rS
            for (m=0; m<count_r; m++) {
                tmp[m] = r[m];
            }
            
            for (n=0; n<count_s; n++) {
                tmp[count_r + n] = s[count_s -1-n];
            }
            
            sr_count +=check(sr, tmp, sr_count);
            //Rs
            for (m=0; m<count_r; m++) {
                tmp[m] = r[count_r - 1 - m];
            }
            for (n=0; n<count_s; n++) {
                tmp[count_r + n] = s[n];
            }
            sr_count +=check(sr, tmp, sr_count);
            //sR
            for (m=0; m<count_s; m++) {
                tmp[m] = s[m];
            }
            for (n=0; n<count_r; n++) {
                tmp[count_s + n] = r[count_r - 1 - n];
            }
            sr_count +=check(sr, tmp, sr_count);
            //RS
            
            for (m=0; m<count_r; m++) {
                tmp[m] = r[count_r - 1 - m];
            }
            for (n=0; n<count_s; n++) {
                tmp[count_r + n] = s[count_s -1-n];
            }
            sr_count +=check(sr, tmp, sr_count);
            //SR
            for (n=0; n<count_s; n++) {
                tmp[n] = s[count_s -1-n];
            }
            for (m=0; m<count_r; m++) {
                tmp[count_s + m] = r[count_r - 1 - m];
            }
            sr_count +=check(sr, tmp, sr_count);
            
            count_s=0;
            count_r=0;
        }
        
        printf("%d\n",sr_count);
        sr_count=0;
        
    }
    
    return 0;
}