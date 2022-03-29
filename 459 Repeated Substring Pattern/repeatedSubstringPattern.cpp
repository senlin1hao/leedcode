#include <iostream>
#include <string>

using namespace std;

// KMP算法
class Solution
{
public:
    bool repeatedSubstringPattern(string s)
    {
        int next[10000];
        int j = 0;
        next[0] = 0;

        for (int i = 1; i < s.size(); i++)
        {
            //不匹配
            while ((j > 0) && (s[i] != s[j]))
            {
                j = next[j - 1];
            }

            //匹配
            if (s[i] == s[j])
            {
                ++j;
            }

            next[i] = j;
        }

        if ((next[s.size() - 1] != 0) && ((s.size() % (s.size() - next[s.size() - 1])) == 0))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};