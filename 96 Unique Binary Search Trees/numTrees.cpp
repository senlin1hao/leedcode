#include <iostream>
#include <string.h>

using namespace std;

class Solution
{
public:
    int numTrees(int n)
    {
        int dp[20];
        memset(dp, 0, sizeof(int) * 20);
        dp[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};