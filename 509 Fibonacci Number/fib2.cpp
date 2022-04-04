#include <iostream>

using namespace std;

//动态规划
class Solution
{
private:
    int dp[31];

public:
    int fib(int n)
    {
        dp[0] = 0;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};