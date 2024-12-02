#include <stdio.h>
int main (){
int i=-1,j=-1,c=0,s3=0;
char ny[11],ny2[1001];
while (1){
i++;
scanf ("%c",&ny[i]);
if (ny[i]==10)break;
}
while (1){
j++;
scanf ("%c",&ny2[j]);
 if (ny2[j]==10){
   if (ny2[j-1]==84){
     if (ny2[j-2]==88){
       if (ny2[j-3]==69){
         if (ny2[j-4]==84){
           if (ny2[j-5]==95){
             if (ny2[j-6]==70){
               if (ny2[j-7]==79){
                 if (ny2[j-8]==95){
                   if (ny2[j-9]==68){
                     if (ny2[j-10]==78){
                       if (ny2[j-11]==69){
                                        break;
                                       }
                                    }
                                 }
                              }
                           }
                        }
                     }
                  }
               }
            }
         }
      }
}
for (int s=0;s<j;s++){
        if (ny2[s]==ny[0]){
        //--------------------------------------//
                for (int s2=s;s2<i+s;s2++){
                        if (ny2[s2]==ny[s3]){
                        s3++;  if (s2==i+s-1)c++;
                        }
                        else if (ny2[s2]!=ny[s3])break;
                }
        //--------------------------------------//
        }s3=0;
}
//-------------------//
printf ("%d\n",c);
//-------------------//
return 0;
}