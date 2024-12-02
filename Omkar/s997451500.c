int main(void){
  int m,n;
  
  scanf("%d %d",&n,&m);
  int a[n];
  int i;
  int sum = 0;
  for(i = 0;i < n;i++){
    scanf("%d",&a[i]);
    sum+=a[i];
  }
  int th = sum/(4*m);
  int cnt=0;
  for(i=0;i < n;i++){
    if(th < a[i]){
      cnt++;
    }
  }
  if(cnt >= m){
    printf("Yes");
  }
  else{
    printf("No");
  }
  return 0;
}
  