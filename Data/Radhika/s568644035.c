#include <stdio.h>

int main(void) {
	int n;
	int c[50];
	int i,j;
	int case_no=1;
	while(1) {
		scanf("%d",&n);
		if(n==0)break;
		for(i=0;i<n;i++)scanf("%d",&c[i]);
		if(c[0]!=1) {
			printf("Case #%d: Cannot pay some amount\n",case_no);
		} else {
			for(i=1;i>0 && i<n;i++) {
				for(j=0;j<i;j++) {
					if(c[i]%c[j]!=0) {
						i=-1;
						break;
					}
				}
			}
			printf("Case #%d: %s\n",case_no,
				i>=n?"OK":"Cannot use greedy algorithm");
		}
		case_no++;
	}
	return 0;
}