#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        vector<vector<int>> dp(2, vector<int>(4, 0));

        dp[0][0] = -prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            dp[1][0] = max(dp[0][0], max(dp[0][2] - prices[i], dp[0][3] - prices[i])); // 买入
            dp[1][1] = dp[0][0] + prices[i];                                           // 今天卖出
            dp[1][2] = max(dp[0][2], dp[0][3]);                                        // 保持卖出
            dp[1][3] = dp[0][1];                                                       // 冷冻期

            dp[0].assign(dp[1].begin(), dp[1].end());
        }

        return max(dp[1][1], max(dp[1][2], dp[1][3]));
    }
};
