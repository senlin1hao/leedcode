#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//动态规划，使用滚动数组，时间复杂度O(n)，空间复杂度O(1)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int dp[2] = {-prices[0], 0};
        for (int i = 1; i < prices.size(); i++)
        {
            dp[1] = max(dp[1], prices[i] + dp[0]); //注意先计算dp[1]，防止dp[0]被覆盖
            dp[0] = max(dp[0], -prices[i]);
        }
        
        return dp[1];
    }
};