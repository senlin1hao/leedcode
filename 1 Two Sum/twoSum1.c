/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//暴力法
#include <stdio.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    *returnSize = 2;
    int *returnNum = (int *)malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                returnNum[0] = i;
                returnNum[1] = j;
                return returnNum;
            }
        }
    }
    return NULL;
}