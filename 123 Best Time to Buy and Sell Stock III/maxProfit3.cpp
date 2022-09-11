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
        vector<int> dp(5, 0);
        dp[1] = dp[3] = -prices[0];
    }
};