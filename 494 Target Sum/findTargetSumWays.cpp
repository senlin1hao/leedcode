#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = 0;
        for (int i : nums)
        {
            sum += i;
        }

        if (((sum + target) % 2) || (abs(target) > sum))
        {
            return 0;
        }

        int t = (sum - target) / 2;
        int dp[1001];
        memset(dp, 0, sizeof(int) * 1001);
        dp[0] = 1;

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = t; j >= nums[i]; j--)
            {
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp[t];
    }
};