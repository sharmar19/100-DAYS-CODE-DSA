/*Problem: Given an array of integers, rotate the array to the right by k positions.

Input:
- First line: integer n
- Second line: n integers
- Third line: integer k

Output:
- Print the rotated array

Example:
Input:
5
1 2 3 4 5
2

Output:
4 5 1 2 3*/

#include <stdio.h>
#include <stdlib.h>

void rotate_and_print() {
    int n, k;
    if (scanf("%d", &n) != 1) return;

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (scanf("%d", &k) != 1) {
        free(arr);
        return;
    }

    k = k % n;

    for (int i = 0; i < n; i++) {
        int index = (n - k + i) % n;
        printf("%d ", arr[index]);
    }

    printf("\n");
    free(arr);
}

int main() {
    rotate_and_print();
    return 0;
}