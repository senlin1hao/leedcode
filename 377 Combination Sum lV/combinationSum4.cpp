#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int combinationSum4(vector<int> &nums, int target)
    {
        //结果不超过int，但中间结果存在超出int范围的dp[i]，使用unsigned int
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        //注意是排列问题，应先遍历背包容量再遍历物品
        for (int i = 0; i <= target; i++)
        {
            for (int num : nums)
            {
                if (i >= num)
                {
                    dp[i] += dp[i - num];
                }
            }
        }

        return dp[target];
    }
};