#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// 动态规划
class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        vector<int> dp(nums.size(), nums[0]);
        int maxSum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > maxSum)
            {
                maxSum = dp[i];
            }
        }

        // 最大值不一定是dp[nums.size() - 1]
        return maxSum;
    }
};