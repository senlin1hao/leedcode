#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// 贪心
class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int maxSum = INT_MIN;
        int tempSum = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            tempSum += nums[i];
            if (tempSum > maxSum)
            {
                maxSum = tempSum;
            }
            if (tempSum < 0)
            {
                tempSum = 0;
            }
        }

        return maxSum;
    }
};