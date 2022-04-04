#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//动态规划
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int dp[1001];
        dp[0] = cost[0];
        dp[1] = cost[1];
        cost.push_back(0);
        for (int i = 2; i < cost.size(); i++)
        {
            dp[i] = min(dp[i - 1] + cost[i], dp[i - 2] + cost[i]);
        }
        return dp[cost.size() - 1];
    }
};