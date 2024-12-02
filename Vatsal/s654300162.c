#include <stdio.h>
#include <string.h>

int main() {
	char string[1000][32], str[32];
	int i=0, md=0, sd=0, c=0, strn[1000];
	unsigned int mlen;

	while(scanf("%s",&str)!=EOF) {
		
		for(i=0;i<=c;i++) {
			if (strcmp(string[i], str)==0) {
				strn[i]++;
				if (strn[i]>strn[sd]) sd=i;
				break;
			}
			if (i==c) {
				strncpy( string[c+1], str, strlen(str) );
				if ( mlen<strlen(string[c+1]) ) {
					md = c+1;
					mlen = strlen(string[c+1]);
				}
				strn[c+1]=1;
				c++;
			}
		}
	}
	printf("%s %s\n",string[sd],string[md]);
	return 0;
}