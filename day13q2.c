// https://leetcode.com/problems/spiral-matrix/

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int rows = matrixSize;
    int cols = matrixColSize[0];
    int totalElements = rows * cols;
    int* result = (int*)malloc(totalElements * sizeof(int));
    *returnSize = 0;

    int top = 0, bottom = rows - 1;
    int left = 0, right = cols - 1;

    while (*returnSize < totalElements) {
        for (int i = left; i <= right && *returnSize < totalElements; i++) {
            result[(*returnSize)++] = matrix[top][i];
        }
        top++;

        for (int i = top; i <= bottom && *returnSize < totalElements; i++) {
            result[(*returnSize)++] = matrix[i][right];
        }
        right--;

        for (int i = right; i >= left && *returnSize < totalElements; i--) {
            result[(*returnSize)++] = matrix[bottom][i];
        }
        bottom--;

        for (int i = bottom; i >= top && *returnSize < totalElements; i--) {
            result[(*returnSize)++] = matrix[i][left];
        }
        left++;
    }

    return result;
}