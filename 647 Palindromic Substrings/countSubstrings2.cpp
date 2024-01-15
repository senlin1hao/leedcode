#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// 中心拓展
class Solution
{
public:
    int countSubstrings(string s)
    {
        int count = 0;

        for (int i = 0; i < 2 * s.size() - 1; i++)
        {
            int left = i / 2;
            int right = i / 2 + i % 2;

            while ((left >= 0) && (right < s.size()) && (s[left] == s[right]))
            {
                --left;
                ++right;
                ++count;
            }
        }

        return count;
    }
};