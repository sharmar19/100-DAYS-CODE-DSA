//https://www.geeksforgeeks.org/problems/missing-number-in-array1416/1

int missingNum(int *arr, int size) {
    long long n = size + 1;
    
    long long s1 = (n * (n + 1)) / 2;
    
    long long s2 = 0;
    
    for (int i = 0; i < size; i++) {
        s2+=arr[i];
    }
    
    int element=(int)(s1-s2);
    
    return element;
}
