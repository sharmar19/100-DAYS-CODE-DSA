/*Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the reversed array, space-separated

Example:
Input:
5
1 2 3 4 5

Output:
5 4 3 2 1

Explanation: Swap pairs from both ends: (1,5), (2,4), middle 3 stays*/

#include<stdio.h>

int main(){

    int n,i;

    printf("Enter the length of the array: "); scanf("%d",&n);

    int array[n];

    for(i=0;i<n;i++){
        printf("Enter the %d element of the array: ",i+1); scanf("%d",&array[i]);
    }

    int a=0,b=n-1,c;

    while(a<b){
        c=array[a];
        array[a]=array[b];
        array[b]=c;
        a++;
        b--;
    }

    printf("The reversed array is: \n");

    for(i=0;i<n;i++)
    printf("%d ",array[i]);

    return 0;
}