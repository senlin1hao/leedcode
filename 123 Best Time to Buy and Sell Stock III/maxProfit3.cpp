#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

//动态规划，时间复杂度O(n)，空间复杂度O(1)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<int> dp(5, 0);
        dp[1] = dp[3] = -prices[0];

        for (int i = 1; i < prices.size(); i++)
        {
            dp[1] = max(dp[1], dp[0] - prices[i]);
            dp[2] = max(dp[2], dp[1] + prices[i]);
            dp[3] = max(dp[3], dp[2] - prices[i]);
            dp[4] = max(dp[4], dp[3] + prices[i]);
        }
        
        return dp[4];
    }
};