/**
 * This is a demo task.

Write a function:

int solution(int A[], int N);

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 6
// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) {
    // write your code in C99 (gcc 6.2.0)
    int min = 1;
    int max = 1;
    int solution = 0;
    int gapFound = 0;
    int valueFound = 0;

    for (int i = 0; i < N; i++) {
        if (A[i] > max) {
            printf("new max, A[%d] = %d\n", i, A[i]);
            min = max;
            max = A[i];
        }
    }

    // find gap (if any)
    if (max - min > 1) {
        solution = max - 1;
    }

    printf("found max %d with min %d\n", max, min);

    // sweep to find solution
    for (int i = max - 1; i > 0; i--) {
        for (int j = 0; j < N; j++) {
            if (A[j] == i) {
                valueFound = 1;
            }
        }
        if (!valueFound) {
            gapFound = 1;
            solution = i;
            break;
        }
    }

    if (!gapFound) {
        printf("found no gap\n");
        if (max == 1) {
            solution = 1;
        } else {
            solution = max + 1;
        }
    }

    return solution;
}


int main(void) {
    int n = SIZE;
    int arrayA[SIZE] = {1, 3, 6, 4, 1, 2};
    int arrayB[3] = {1,2,3};
    printf("solutionA = %d\n", solution(arrayA, n));
    printf("solutionB = %d\n", solution(arrayB, 3));
    return 0;
}