#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> bracketStack;
        for (char c : s)
        {
            switch (c)
            {
            case '(':
            case '{':
            case '[':
                bracketStack.push(c);
                break;

            case ')':
            {
                if ((bracketStack.empty()) || (bracketStack.top() != '('))
                {
                    return false;
                }
                else
                {
                    bracketStack.pop();
                }

                break;
            }

            case '}':
            {
                if ((bracketStack.empty()) || (bracketStack.top() != '{'))
                {
                    return false;
                }
                else
                {
                    bracketStack.pop();
                }

                break;
            }

            case ']':
            {
                if ((bracketStack.empty()) || (bracketStack.top() != '['))
                {
                    return false;
                }
                else
                {
                    bracketStack.pop();
                }

                break;
            }

            default:
                break;
            }
        }

        return bracketStack.empty();
    }
};