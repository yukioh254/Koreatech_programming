#include <stdio.h>
#include <string.h>
#include <math.h>

int charToValue(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10;
    }
    return -1; 
}

int main() {
    char N[36];
    int B;

    scanf("%s %d", N, &B);
    
    int len = strlen(N);
    long long result = 0;

    for (int i = 0; i < len; i++) {
        int value = charToValue(N[i]);
        result = result * B + value;
    }

    printf("%lld\n", result);

    return 0;
}