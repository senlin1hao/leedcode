#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// 动态规划，时间复杂度O(n^2)
class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        vector<int> dp(nums.size(), 1);
        int maxLength = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }

            if (dp[i] > maxLength)
            {
                maxLength = dp[i];
            }
        }

        return maxLength;
    }
};
