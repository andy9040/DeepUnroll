#include <stdio.h>
int M(char s[]){
	int i,n,m,a[20];
	for(i=0,n=0;s[i];i+=2)
		a[n++]=s[i]-'0';
	for(i=1;s[i];i+=2){
		if(s[i]=='*'){
			a[i/2]*=a[i/2+1];
			a[i/2+1]=0;
		}
	}
	for(i=0,m=0;i<n;i++)
		m+=a[i];
	return m;
}
int L(char s[]){
	int i,l;
	for(i=1,l=s[0]-'0';s[i];i+=2){
		if(s[i]=='+')
			l+=s[i+1]-'0';
		else if(s[i]=='*')
			l*=s[i+1]-'0';
	}
	return l;
}
int main(void){
	int i,m,l,b;
	char s[20];
	scanf("%s",s);
	scanf("%d",&b);
	m=M(s);
	l=L(s);
	if(b==m&&b==l)
		puts("U");
	else if(b==m)
		puts("M");
	else if(b==l)
		puts("L");
	else
		puts("I");
	return 0;
}