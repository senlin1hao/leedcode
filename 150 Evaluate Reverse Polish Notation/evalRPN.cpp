#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> nums;
        for (string s : tokens)
        {
            if (!s.compare("+"))
            {
                int n1 = nums.top();
                nums.pop();
                int n2 = nums.top();
                nums.pop();
                nums.push(n2 + n1);
            }
            else if (!s.compare("-"))
            {
                int n1 = nums.top();
                nums.pop();
                int n2 = nums.top();
                nums.pop();
                nums.push(n2 - n1);
            }
            else if (!s.compare("*"))
            {
                int n1 = nums.top();
                nums.pop();
                int n2 = nums.top();
                nums.pop();
                nums.push(n2 * n1);
            }
            else if (!s.compare("/"))
            {
                int n1 = nums.top();
                nums.pop();
                int n2 = nums.top();
                nums.pop();
                nums.push(n2 / n1);
            }
            else
            {
                int n = stoi(s);
                nums.push(n);
            }
        }

        return nums.top();
    }
};