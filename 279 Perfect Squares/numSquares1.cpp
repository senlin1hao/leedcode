#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

//完全背包动态规划
class Solution
{
public:
    int numSquares(int n)
    {
        int squaresSize = sqrt(n);
        vector<int> squares(squaresSize);
        for (int i = 1; i <= squaresSize; i++)
        {
            squares[i - 1] = i * i;
        }

        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int square : squares)
        {
            for (int i = square; i <= n; i++)
            {
                dp[i] = min(dp[i], dp[i - square] + 1);
            }
        }

        return dp[n];
    }
};