#include <stdio.h>
#include <string.h>

int a[1000000]={0}, x, y=0, z=0;
void insert()
{
  a[y] = x;
  y++;
  return;
}

void delete()
{
  int i, j;
  for(i = y-1; i >= 0; i--){
    if(a[i] == x){
      for(j = i; j < y-1; j++){
        a[j] = a[j+1];
      }
      y--;
      break;
    }
  }
  return;
}

void deleteLast()
{
  int i;
  for(i = 0; i < y-1; i++){
    a[i] = a[i+1];
  }
  y--;
  return;
}

void deleteFirst()
{
  a[y-1] = 0;
  y--;
  return;
}

int main()
{
  long long int n, i;
  char str[32];
  scanf("%d", &n);
  for(i = 0; i < n; i++){
    scanf("%s", str);
    if(str[0] == 'i'){
      scanf("%d", &x);
      insert();
    } else if(str[0] == 'd'){
      if(strlen(str) > 6){
        if(str[6] == 'F') deleteFirst();
        else if(str[6] == 'L') deleteLast();
      } else {
        scanf("%d", &x);
        delete();
      }
    } 
  }
  for(i = y-1; i >= 0; i--){
    if(i == 0) printf("%d\n", a[i]);
    else printf("%d ", a[i]);
  }
  return 0;
}