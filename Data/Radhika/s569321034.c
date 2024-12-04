#include <stdio.h>
#include <string.h>

int main() {
	char str;
	scanf("%s",&str);
	if (strcmp("SUN",&str) == 0) {
		printf("7");
	}
	else if (strcmp("MON", &str) == 0) {
		printf("6");
	}
	else if (strcmp("TUE", &str) == 0) {
		printf("5");
	}
	else if (strcmp("WED", &str) == 0) {
		printf("4");
	}
	else if (strcmp("THU", &str) == 0) {
		printf("3");
	}
	else if (strcmp("FRI", &str) == 0) {
		printf("2");
	}
	else if (strcmp("SAT", &str) == 0) {
		printf("1");
	}
	return 0;
}