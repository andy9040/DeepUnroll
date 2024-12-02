#include <stdio.h>
#include <stdlib.h>

int check(long x,long y,long z){
  long two = 536870912;
  long tmpx,tmpy,tmpz;
  //printf("%ld %ld %ld\n",x,y,z);
  while(two > 2){
    tmpx = x / two;
    tmpy = y / two;
    tmpz = z / two;
    if((tmpx + tmpy + tmpz) % 2 != 0){
      return -1;
    }
    x -= tmpx*two;
    y -= tmpy*two;
    z -= tmpz*two;
    two /= 2;
  }
  //printf("%ld %ld %ld\n",x,y,z);
  if((x/2 + y/2 + z/2) % 2 != 0) return -1;
  if((x%2 + y%2 + z%2) % 2 != 0) return -1;
  return 1;
}

int main(){
  int n;
  long a[100000];
  scanf("%d",&n);
  int z = 1;
  for(int i=0;i<n;i++){
    scanf("%ld",&a[i]);
    if(a[i] != 0){
      z = 0;
    }
  }
  //printf("%ld %ld %ld\n",a[0],a[1],a[2]);
  if(z == 1){
    printf("Yes\n");
  }else if(n % 3 != 0){
    printf("No\n");
  }else{
    long buf[3] = {};
    int count[3] = {};
    int i,j;
    buf[0] = a[0];
    //printf("buf %ld a %ld\n",buf[0],a[0]);
    count[0] = 1;
    for(i=1;i<n;i++){
      if(a[i] == buf[0]){
        count[0] += 1;
      }else{
        buf[1] = a[i];
        count[1] = 1;
        j = i + 1;
        break;
      }
    }
    for(i=j;i<n;i++){
      if(a[i] == buf[0]){
        count[0] += 1;
      }else if(a[i] == buf[1]){
        count[1] += 1;
      }else{
        buf[2] = a[i];
        count[2] = 1;
        j = i + 1;
        break;
      }
    }
    if(i == n){
      if(buf[0] == 0 && count[0] == n/3){
        printf("Yes\n");
      }else if(buf[1] == 0 && count[1] == n/3){
        printf("Yes\n");
      }else{
        printf("No\n");
      }
    }else if(n/3 == 1 || j != n){
      for(i=j;i<n;i++){
        if(a[i] == buf[0]){
          count[0] += 1;
        }else if(a[i] == buf[1]){
          count[1] += 1;
        }else if(a[i] == buf[2]){
          count[2] += 1;
        }else{
          printf("No\n");
          break;
        }
      }
      if(count[0] == n/3 && count[1] == n/3 && count[2] == n/3){
        if(check(buf[0],buf[1],buf[2]) == 1){
          printf("Yes\n");
        }else{
          printf("No\n");
        }
      }else{
        printf("No\n");
      }
    }else{
      printf("No\n");
    }
  }
  return 0;
}