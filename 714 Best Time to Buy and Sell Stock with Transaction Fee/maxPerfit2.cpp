#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// 动态规划
class Solution
{
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        vector<vector<int>> dp(2, vector<int>(2, 0));

        dp[0][0] = -prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            dp[1][0] = max(dp[0][0], dp[0][1] - prices[i]);
            dp[1][1] = max(dp[0][1], dp[0][0] + prices[i] - fee);
            dp[0][0] = dp[1][0];
            dp[0][1] = dp[1][1];
        }

        return max(dp[1][0], dp[1][1]);
    }
};
