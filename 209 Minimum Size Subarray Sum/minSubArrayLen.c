#include <stdio.h>
#include <limits.h>
#include <math.h>

//滑动窗口，O(n)
int minSubArrayLen(int target, int* nums, int numsSize)
{
    int start = 0;
    int end = 0;
    int minLen = INT_MAX;
    int sum = 0;
    while (end < numsSize)
    {
        sum += nums[end];
        while (sum >= target)
        {
            minLen = fmin(minLen, end - start + 1);
            sum -= nums[start];
            ++start;
        }
        ++end;
    }
    return (minLen == INT_MAX ? 0 : minLen);
}