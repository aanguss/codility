/**
 * A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps. The number 32 has binary representation 100000 and has no binary gaps.

Write a function:

int solution(int N);

that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5. Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..2,147,483,647].
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// int solution(int N) {
//     int gap = 0;
//     char* nString = malloc(1);
//     nString[0] = '\0';
//     int len;
//     char* tempString = malloc(1);
//     tempString[0] = '\0';
//     int Q = 0;
//     char qS;
//     char qString[100];
//     printf("N = %d\n", N);
//     Q = N % 2;
//     sprintf(qString, "%d", Q);
//     printf("qString = %c\n", qString[0]);
//     // strncat(nString, &qString[0], 1); 
//     // strcat(nString, &qString[0]);
//     tempString = malloc(strlen(tempString) + 1);
//     nString = malloc(strlen(nString) + 1);
//     strcpy(tempString, nString);
//     tempString[strlen(tempString)-1] = qString[0];
//     tempString[strlen(tempString)] = '\0';
//     strcpy(nString, tempString);
    

//     // strncat(nString,&qString[0],1);
//     N = N / 2;
//     printf("nString = %s\n", nString);
//     printf("N = %d\n", N);
//     printf("Q = %d\n", Q);
//     Q = N % 2;
//     N = N / 2;
//     printf("N = %d\n", N);
//     printf("Q = %d\n", Q);
//     Q = N % 2;
//     N = N / 2;
//     printf("N = %d\n", N);
//     printf("Q = %d\n", Q);
//     Q = N % 2;
//     N = N / 2;
//     printf("N = %d\n", N);
//     printf("Q = %d\n", Q);
//     Q = N % 2;
//     N = N / 2;
//     printf("N = %d\n", N);
//     printf("Q = %d\n", Q);
//     Q = N % 2;
//     N = N / 2;
//     printf("N = %d\n", N);
//     printf("Q = %d\n", Q);
//     Q = N % 2;
//     N = N / 2;
//     printf("N = %d\n", N);
//     printf("Q = %d\n", Q);
//     Q = N % 2;
//     N = N / 2;
//     printf("N = %d\n", N);
//     printf("Q = %d\n", Q);
//     Q = N % 2;
//     N = N / 2;
//     printf("N = %d\n", N);
//     printf("Q = %d\n", Q);
//     Q = N % 2;
//     N = N / 2;
//     printf("N = %d\n", N);
//     printf("Q = %d\n", Q);
//     Q = N % 2;
//     N = N / 2;
//     printf("N = %d\n", N);
//     printf("Q = %d\n", Q);
//     Q = N % 2;
//     N = N / 2;

//     return 0;
// }

int solution(int N) {
    int gap = 0;
    int largestGap = 0;
    int Q = 0;
    
    while (N != 0) {
        Q = N % 2;
        N = N / 2;
        if (!Q) {
            gap++;
            if (gap > largestGap) {
                largestGap = gap;
            }
        } else {
            gap = 0;
        }
        printf("N: %d, Q:%d\n", N, Q);
    }

    return largestGap;
}

int main(void) {
    int val = 1041;
    printf("binary gap of %d = %d\n", val, solution(val));

    return 0;
}