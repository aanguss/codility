// problem 1 from Toptal screening test
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(char *S, int K) {
    // save new solution in new array to be copied back into S
     char *newArray = malloc( sizeof(char) * ( K + 1 ) );
    int newArrayIndex = 0;
    uint16_t sameCharCount = 0; // keep track of same characters
    char sameChar[5];
    

    for (int i = 0; i < K - 1; i++) {
        sameCharCount = 0;
        for (int j = i + 1; j <= K; j++) {
            if (S[i] == S[j]) {
                printf("found same char: %c\n", S[i]);
                sameCharCount++;
            } else {
                if (sameCharCount != 0) {
                    sprintf(sameChar, "%d", sameCharCount);
                    newArray[newArrayIndex++] = sameChar;
                    printf("adding %d to newArray\n", sameCharCount);
                }
                newArray[newArrayIndex++] = S[i];
                i += sameCharCount;
                break;
            }
        }
    }

    printf("new array:\n");
    for (int i = 0; i < K; i++) {
        printf("%c ", newArray[i]);
    }
    
    return 1;
}

int main(void) {
    int aSize = 9;
    char * arrayA = "abcdddefg";
    
    printf("\nsolutionA = %d\n", solution(arrayA, aSize));

    return 0;   
}