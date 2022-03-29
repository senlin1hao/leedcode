#include <iostream>
#include <string>

using namespace std;

/*
首先扩充数组到每个空格替换成"%20"之后的大小,
然后从后向前替换空格，使用双指针法，时间复杂度为O(n)，
从前向后填充时间复杂度为O(n^2)，因为每次添加元素都要将添加元素之后的所有元素向后移动。
*/
class Solution
{
public:
    string replaceSpace(string s)
    {
        int spaceCount = 0;
        int oldSize = s.size();
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                ++spaceCount;
            }
        }
        
        s.resize(oldSize + spaceCount * 2);
        int newSize = s.size();

        int p1 = oldSize - 1;
        int p2 = newSize - 1;
        while (spaceCount > 0)
        {
            if (s[p1] == ' ')
            {
                s[p2--] = '0';
                s[p2--] = '2';
                s[p2--] = '%';
                --p1;
                --spaceCount;
            }
            else
            {
                s[p2--] = s[p1--];
            }
        }
        
        return s;
    }
};