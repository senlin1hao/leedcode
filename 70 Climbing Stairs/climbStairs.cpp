#include <iostream>

using namespace std;

/*
动态规划
到第n阶有从第n-1阶或第n-2阶2种方法
dp[n] = dp[n - 1] + dp[n + 1]
*/
class Solution
{
public:
    int climbStairs(int n)
    {
        int dp[46];
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};