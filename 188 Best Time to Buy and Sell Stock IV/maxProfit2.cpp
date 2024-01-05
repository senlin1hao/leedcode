#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// 动态规划，时间复杂度O(k * n)，空间复杂度O(k)
class Solution
{
public:
    int maxProfit(int k, vector<int>& prices)
    {
        vector<int> dp(2 * k + 1, 0);

        for (int j = 1; j < 2 * k + 1; j += 2)
        {
            dp[j] = -prices[0];
        }

        for (int i = 1; i < prices.size(); i++)
        {
            for (int j = 1; j < 2 * k + 1; j += 2)
            {
                dp[j] = max(dp[j], dp[j - 1] - prices[i]);
                dp[j + 1] = max(dp[j + 1], dp[j] + prices[i]);
            }
        }

        return dp[2 * k];
    }
};
