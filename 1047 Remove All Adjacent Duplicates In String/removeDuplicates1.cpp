#include <iostream>
#include <string>

using namespace std;

//双指针法，原地修改
class Solution
{
public:
    string removeDuplicates(string s)
    {
        int p1 = 0;
        int p2 = 0;
        while (p1 < s.size())
        {
            if (s[p1] == s[p1 + 1])
            {
                p1 += 2;
            }
            else if ((p2 > 0) && (s[p1] == s[p2 - 1]))
            {
                ++p1;
                --p2;
            }
            else
            {
                s[p2++] = s[p1++];
            }
        }

        s.resize(p2);
        return s;
    }
};
