#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// 动态规划
class Solution
{
public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        vector<int> dp(nums.size(), 1);
        int maxLength = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                dp[i] = dp[i - 1] + 1;
            }
            if (dp[i] > maxLength)
            {
                maxLength = dp[i];
            }
        }

        return maxLength;
    }
};