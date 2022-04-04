#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

class Solution
{
public:
    int integerBreak(int n)
    {
        int dp[59];
        memset(dp, 0, sizeof(int) * 59);
        dp[2] = 1;
        dp[3] = 2;
        
        for (int i = 4; i <= n; i++)
        {
            for (int j = i / 2; j >= 2; j--)
            {
                //j不用分解
                dp[i] = max(dp[i], j * dp[i - j]);
                dp[i] = max(dp[i], j * (i - j));
            }
        }
        return dp[n];
    }
};