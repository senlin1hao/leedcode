/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//双指针法，O(n)，逆序存放，不需要考虑移动到边界
#include <math.h>

int *sortedSquares(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;
    int *returnNums = (int *)malloc(sizeof(int) * numsSize);
    int left = 0;
    int right = numsSize - 1;
    
    for (int i = numsSize - 1; i >= 0; i--)
    {
        if (abs(nums[left]) < abs(nums[right]))
        {
            returnNums[i] = nums[right] * nums[right];
            --right;
        }
        else
        {
            returnNums[i] = nums[left] * nums[left];
            ++left;
        }
    }
    return returnNums;
}