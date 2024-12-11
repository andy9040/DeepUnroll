#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Programming in C";
    int freq[256] = {0};
    int maxFreq = 0;
    char mostFreqChar;

    for (int i = 0; str[i] != '\0'; i++) {
        freq[(int)str[i]]++;
        if (freq[(int)str[i]] > maxFreq) {
            maxFreq = freq[(int)str[i]];
            mostFreqChar = str[i];
        }
    }

    printf("Most frequent character: '%c' with frequency %d\n", mostFreqChar, maxFreq);
    return 0;
}
