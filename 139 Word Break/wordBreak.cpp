#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int p1, p2;
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());

        for (int i = 1; i <= s.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                string str(s, j, i - j);
                if ((wordSet.find(str) != wordSet.end()) && dp[j])
                {
                    dp[i] = true;
                }
            }
        }

        return dp[s.size()];
    }
};