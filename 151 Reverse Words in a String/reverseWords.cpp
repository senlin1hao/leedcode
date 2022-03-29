#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        while (s.back() == ' ')
        {
            s.pop_back();
        }
        
        int p1 = 0;
        int p2 = 0;
        while (p2 < s.size())
        {
            if (s[p2] == ' ')
            {
                while (s[p2 + 1] == ' ')
                {
                    ++p2;
                }
            }
            s[p1++] = s[p2++];
        }
        s.resize(p1);
        
        reverse(s.begin(), s.end());

        while (s.back() == ' ')
        {
            s.pop_back();
        }

        p1 = 0;
        p2 = 1;
        
        while (p1 < s.size())
        {
            while (s[p2] != ' ' && p2 < s.size())
            {
                ++p2;
            }
            reverse(s.begin() + p1, s.begin() + p2);
            p1 = p2 + 1;
            p2 = p1 + 1;
        }
        
        return s;
    }
};