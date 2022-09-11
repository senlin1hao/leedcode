#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
        dp[0] = dp[2] = dp[4] = 0;
        dp[1] = dp[3];
    }
};