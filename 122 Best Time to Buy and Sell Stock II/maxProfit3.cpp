#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//动态规划，滚动数组
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int dp[2][2] = {{-prices[0], 0}, {0, 0}};
        for (int i = 1; i < prices.size(); i++)
        {
            dp[i % 2][0] = max(dp[(i + 1) % 2][0], dp[(i + 1) % 2][1] - prices[i]);
            dp[i % 2][1] = max(dp[(i + 1) % 2][1], dp[(i + 1) % 2][0] + prices[i]);
        }

        return dp[(prices.size() - 1) % 2][1];
    }
};