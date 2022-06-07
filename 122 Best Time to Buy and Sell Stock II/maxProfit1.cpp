#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//贪心算法
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<int> profits(prices.size() - 1, 0);
        for (int i = 0; i < profits.size(); i++)
        {
            profits[i] = prices[i + 1] - prices[i];
        }
        
        int profit = 0;

        for (int i : profits)
        {
            if (i > 0)
            {
                profit += i;
            }
        }
        
        return profit;
    }
};