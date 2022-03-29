#include <iostream>
#include <string>

using namespace std;

// KMP算法：用于匹配字符串
class Solution
{
public:
    //生成next数组
    void getNext(int *next, string s)
    {
        int j = 0;
        next[0] = 0;
        for (int i = 1; i < s.size(); i++)
        {
            //注意处理完不匹配后还需判断是否匹配

            //不匹配
            while ((j > 0) && (s[j] != s[i]))
            {
                j = next[j - 1];
            }

            //匹配
            if (s[j] == s[i])
            {
                ++j;
            }

            next[i] = j;
        }

        return;
    }

    int strStr(string haystack, string needle)
    {
        if (needle.empty())
        {
            return 0;
        }

        int next[50000];
        getNext(next, needle);

        int j = 0;
        for (int i = 0; i < haystack.size(); i++)
        {
            //注意处理完不匹配后还需判断是否匹配

            while ((j > 0) && (haystack[i] != needle[j]))
            {
                j = next[j - 1];
            }

            if (haystack[i] == needle[j])
            {
                ++j;
                if (j == needle.size())
                {
                    return (i - j + 1);
                }
            }
        }

        return -1;
    }
};