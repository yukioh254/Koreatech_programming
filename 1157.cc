#include <stdio.h>
#include <ctype.h>

int main () {
    char word[1000001], result = '?';
    
    int count[26] = {0}, max = 0;
    
    scanf("%s", word);
    
    for (int i = 0; word[i]; i++)
        count[toupper(word[i]) - 'A']++;
    
    for (int i = 0; i < 26; i++) {
        if (count[i] > max) {
            max = count[i];
            result = 'A' + i;
        } else if (count[i] == max){
            result = '?';
        }
    }
  
    printf("%c\n", result);
    
    return 0;
}