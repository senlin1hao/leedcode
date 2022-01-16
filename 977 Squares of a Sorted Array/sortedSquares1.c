/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//双指针法，O(n)，顺序存放，需要考虑移动到边界
#include <math.h>

int *sortedSquares(int *nums, int numsSize, int *returnSize)
{
    *returnSize = numsSize;
    int *returnNums = (int *)malloc(sizeof(int) * numsSize);

    int left, right, i;
    for (i = 1; i < numsSize; i++)
    {
        if (abs(nums[i]) > abs(nums[i - 1]))
        {
            break;
        }
    }
    
    returnNums[0] = nums[i - 1] * nums[i - 1];
    left = i - 2;
    right = i;
    i = 1;
    while ((left >= 0) && (right <= numsSize - 1))
    {
        if (abs(nums[left]) < abs(nums[right]))
        {
            returnNums[i] = nums[left] * nums[left];
            --left;
        }
        else
        {
            returnNums[i] = nums[right] * nums[right];
            ++right;
        }
        ++i;
    }
    while (left >= 0)
    {
        returnNums[i] = nums[left] * nums[left];
        --left;
        ++i;
    }
    while (right <= numsSize - 1)
    {
        returnNums[i] = nums[right] * nums[right];
        ++right;
        ++i;
    }

    return returnNums;
}