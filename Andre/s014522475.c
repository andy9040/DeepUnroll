#include <stdio.h>
#define MAX 500000
#define INF 1073741823
int L[MAX],R[MAX];

void merge(int A[],int left,int mid,int right){
  int n1 = mid - left, n2 = right - mid;
  int i,j,k;
  for(i=0; i<n1; ++i) L[i] = A[left+i];
  for(i=0; i<n2; ++i) R[i] = A[mid+i];
  L[n1] = INF; R[n2] = INF;
  //L[n1] = -INF; R[n2] = -INF;
  i=0; j=0;
  for(k=left; k<right; ++k){
    if(L[i]<=R[j])
    //if(L[i]>=R[j])
    {
      A[k] = L[i++];
    }
    else
    {
      A[k] = R[j++];
    }
  }
}
void mergeSort(int A[],int left,int right){
  /*ソートの順番を変えたいときは、
  コメントアウトしているところを入れ替える*/
  int i,mid;
  if(left+1<right){
    mid = (left+right)/2;
    mergeSort(A,left,mid);
    mergeSort(A,mid,right);
    merge(A,left,mid,right);
  }
}


int main(void) {
  int i,j,n,k,ans,a;
  int l[1000000];
  ans=0;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&l[i]);
  }
  mergeSort(l,0,n);
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(l[i]==l[j])
      break;
      for(k=0;k<n;k++)
      {
        if(l[j]==l[k])
        break;
        else if(l[i]==l[k])
        break;
        else if(l[i]>=l[k]+l[j])
        break;
        else
        {
          ans++;
        }
      }
    }   
  }
  printf("%d",ans);
  return 0;
}

