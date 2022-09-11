#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//动态规划，时间复杂度O(n)，空间复杂度O(n)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
        dp[0][0] = dp[0][2] = dp[0][4] = 0;
        dp[0][1] = dp[0][3] = -prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = 0;
            dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
            dp[i][2] = max(dp[i - 1][1] + prices[i], dp[i - 1][2]);
            dp[i][3] = max(dp[i - 1][2] - prices[i], dp[i - 1][3]);
            dp[i][4] = max(dp[i - 1][3] + prices[i], dp[i - 1][4]);
        }
        
        return dp[prices.size() - 1][4];
    }
};