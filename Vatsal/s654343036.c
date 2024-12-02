#include <stdioh>
int main(){
  int a, b;
  
  scanf("%d %d",&a, &b);
  
  if(2 * a > b){
    printf("safe");
  }
  
  else{
    printf("unsafe");
  }
  
  return 0;
}