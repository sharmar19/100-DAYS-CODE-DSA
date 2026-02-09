/*Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    
    printf("Enter the number of elements: "); scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++){
        printf("Enter the %d element: ",i+1); scanf("%d", &arr[i]);
    }

    int i = 0; 
    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }

    printf("The new array: \n");
    for (int k = 0; k <= i; k++){
        printf("%d", arr[k]);
    }

    free(arr);
    return 0;
}