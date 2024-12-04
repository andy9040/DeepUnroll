#include<stdio.h>
int main(void){
	int tester;//入力のfor文
	int n;//全体の種類
	int m;//選びたい個数
	int a[10000];//個々の得票数
	int sum=0;//総投票数
	int i;//for文周回用
	int mid;//1/4m つまり得票の最低
	int e;//比較のfor文用
	int vot=0;//比較した際 mとの比較用
	scanf("%d%d",&n,&m);
	for(tester=0;tester<n;tester++){
		scanf("%d",&a[tester]);
	}
	//票の合計の計算
	for(i=0;i<=n;i++){
		sum+=a[i];
	}
	//mid算出
	mid=sum/(4*m);
	//比較
	for(e=0;e<n;e++){
		if(a[e]>=mid){
			vot++;
		}
	}
	//出力(判定)
	if(vot>=m){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	return 0;
}