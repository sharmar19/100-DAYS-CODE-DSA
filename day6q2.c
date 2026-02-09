//https://leetcode.com/problems/move-zeroes/

void moveZeroes(int* nums, int numsSize) {
    int a=0;

    for (int i=0;i<numsSize;i++) {
        if (nums[i]!=0) {
            int temp=nums[a];
            nums[a]=nums[i];
            nums[i]=temp;
            
            a++;
        }
    }
}