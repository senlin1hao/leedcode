#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        vector<vector<uint64_t>> dp(t.size() + 1, vector<uint64_t>(s.size() + 1, 0));

        dp[0].assign(s.size(), 1);

        for (int i = 1; i <= t.size(); i++)
        {
            for (int j = 1; j <= s.size(); j++)
            {
                if (t[i - 1] == s[j - 1])
                {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }

        return dp[t.size()][s.size()] % 1000000007;
    }
};
