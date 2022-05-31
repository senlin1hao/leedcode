#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//贪心算法，时间复杂度O(n)，空间复杂度O(1)
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int buy = INT_MAX;
        int profit = 0;

        for (int i : prices)
        {
            buy = min(buy, i);
            profit = max(profit, i - buy);
        }
        
        return profit;
    }
};