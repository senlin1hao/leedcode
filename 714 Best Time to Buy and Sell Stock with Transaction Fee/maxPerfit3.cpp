#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// 贪心
class Solution
{
public:
    int maxProfit(vector<int>& prices, int fee)
    {
        int minPrice = prices[0];
        int result = 0;

        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < minPrice)
            {
                minPrice = prices[i];
                continue;
            }

            if (prices[i] <= minPrice + fee)
            {
                continue;
            }

            if (prices[i] > minPrice + fee)
            {
                result += prices[i] - minPrice - fee;
                minPrice = prices[i] - fee;
            }
        }

        return result;
    }
};
