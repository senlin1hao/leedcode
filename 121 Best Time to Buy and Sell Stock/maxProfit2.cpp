#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//动态规划，时间复杂度O(n)，空间复杂度O(n)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i - 1][0]);
        }
        
        return dp[prices.size() - 1][1];
    }
};