#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//单调栈
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        prices.emplace_back(INT_MIN);
        vector<int> stack;
        int profit = 0;
        for (int i : prices)
        {
            if (!stack.empty() && stack.back() > i)
            {
                profit = max(profit, stack.back() - stack.front());
                while (!stack.empty() && stack.back() > i)
                {
                    stack.pop_back();
                }
            }
            stack.emplace_back(i);
        }

        return profit;
    }
};