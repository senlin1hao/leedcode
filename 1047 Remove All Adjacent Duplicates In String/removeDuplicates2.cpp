#include <iostream>
#include <string>
#include <vector>

using namespace std;

//栈，新建一个字符串
class Solution
{
public:
    string removeDuplicates(string s)
    {
        string result;

        for (char c : s)
        {
            if ((!result.empty()) && (c == result.back()))
            {
                result.pop_back();
            }
            else
            {
                result.push_back(c);
            }
        }
        
        return result;
    }
};