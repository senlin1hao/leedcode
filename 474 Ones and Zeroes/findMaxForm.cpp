#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int zeroCount;
        int oneCount;
        for (string str : strs)
        {
            zeroCount = 0;
            oneCount = 0;
            for (char c : str)
            {
                if (c == '0')
                {
                    ++zeroCount;
                }
                else
                {
                    ++oneCount;
                }
            }

            for (int i = m; i >= zeroCount; i--)
            {
                for (int j = n; j >= oneCount; j--)
                {
                    dp[i][j] = max(dp[i][j], dp[i - zeroCount][j - oneCount] + 1);
                }
            }
        }

        return dp[m][n];
    }
};