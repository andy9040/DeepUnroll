int main(void){
  int n;
  scanf("%d",&n);
  
  int a[n]={},i,m;
  a[0] = 100001;
  
  for(i=0; i<n; i++){
    scanf("%d",&m);
    if(a[i]>m) a[i] = m;
    a[i+1] = m;
  }
  
  int sum=0;
  
  for(i=0; i<n; i++){
    sum += a[i];
  }
  
  printf("%d",sum);
  
  return 0;
}
  
  