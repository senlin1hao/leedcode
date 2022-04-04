#include <iostream>

using namespace std;

//动态规划，降低空间复杂度从O(m*n)到O(n)
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int dp[100];
        for (int i = 0; i < n; i++)
        {
            dp[i] = 1;
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                dp[j] = dp[j - 1] + dp[j];
            }
        }
        return dp[n - 1];
    }
};