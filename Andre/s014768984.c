#include <stdio.h>

int main(){
int a,b;
char s[20];
int pos = 1;
scanf("%d %d",&a,&b);
scanf("%s",s);

if(s[a] != '-'){ //itu [A] karena di index 1,+1 -1 = karena di soal index 1 di awal
	pos = 0;
}

for(int i = 0;s[i]!='\0';i++){ //\0 (selama dia tidak sampai ke null maka loop terus
	if(s[i] != s[a]){//jika karakter bukan di A maka cek(selain -)
		if(s[i]< '0' || s[i]> '9'){ //kalau bukan di rentang ini bye
		 pos = 0;
		 break; //karena false break aja dari loopnya
		}
    }	
}
	//kalau benar dan tidak false print yes
	(pos) ? printf("Yes\n") : printf("No\n");
	return 0;
}