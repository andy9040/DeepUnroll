A[10000],B[10000];z(int*a,int*b){return*b-*a;}
main(n,i,j){for(;scanf("%d",&n),n;puts(i<n?"No":"Yes")){
for(i=0;i<n*2;i++)scanf("%d",A+i);
qsort(A,n,4,z);
for(i=0;i<n;i++){for(j=n;j<n*2;j++)if(A[j])A[i]--,A[j]--;if(A[i])break;}
}exit(0);}