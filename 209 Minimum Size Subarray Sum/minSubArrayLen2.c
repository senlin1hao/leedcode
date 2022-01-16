#include <stdio.h>
#include <limits.h>
#include <math.h>

//二分法，O(nlogn)
int lower_bound(int *nums, int left, int right, int target)
{
    if (nums[right] < target)
    {
        return -1;
    }
    int mid;
    while (left < right)
    {
        mid = (left + right) / 2;
        if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return left;
}

int minSubArrayLen(int target, int* nums, int numsSize)
{
    //sums[i]为nums前i个数之和
    int *sums = (int *)malloc(sizeof(int) * (numsSize + 1));
    sums[0] = 0;
    for (int i = 1; i <= numsSize; i++)
    {
        sums[i] = sums[i - 1] + nums[i - 1];
    }
    
    int minLen = INT_MAX;
    int iMinLen;
    int target1;
    for (int i = 1; i <= numsSize; i++)
    {
        target1 = target + sums[i - 1];
        iMinLen = lower_bound(sums, i, numsSize, target1);
        if (iMinLen != -1)
        {
            minLen = fmin(minLen, iMinLen - i + 1);
        }
    }
    return minLen == INT_MAX ? 0 : minLen;
}