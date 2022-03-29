#include <iostream>
#include <string>

using namespace std;

//每次移动k
class Solution
{
public:
    string reverseStr(string s, int k)
    {
        char c;
        bool isReverse = true;

        for (int i = 0; i < (s.size() + k - 1); i += k)
        {
            if (isReverse)
            {
                int left = i;
                int right = min(i + k - 1, (int)(s.size() - 1));

                while (left < right)
                {
                    c = s[left];
                    s[left] = s[right];
                    s[right] = c;

                    ++left;
                    --right;
                }
            }
            isReverse = !isReverse;
        }

        return s;
    }
};