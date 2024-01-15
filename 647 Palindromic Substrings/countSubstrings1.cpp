#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// 动态规划
class Solution
{
public:
    int countSubstrings(string s)
    {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int count = 0;

        for (int i = s.size() - 1; i >= 0; i--) // 注意遍历顺序
        {
            for (int j = i; j < s.size(); j++)
            {
                if (s[i] == s[j])
                {
                    if (j - i <= 1) // ((i == j) || (i == j - 1))
                    {
                        dp[i][j] = true;
                        ++count;
                    }
                    else if (dp[i + 1][j - 1])
                    {
                        dp[i][j] = true;
                        ++count;
                    }
                }
            }
        }

        return count;
    }
};
