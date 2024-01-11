#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// 贪心
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        int sPosition = 0;
        for (int i = 0; i < t.size(); i++)
        {
            if (s[sPosition] == t[i])
            {
                ++sPosition;
            }
        }

        return (sPosition == s.size());
    }
};