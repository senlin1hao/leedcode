#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

//贪心算法，下方用例过不了
//将第1天买第6天卖分成了第1天买第3天卖和第4天买第6天卖，选择了第1天买第3天卖
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        vector<int> profits(prices.size() - 1);
        for (int i = 0; i < profits.size(); i++)
        {
            profits[i] = prices[i + 1] - prices[i];
        }
        
        priority_queue<int, vector<int>, greater<int>> maxProfits;
        maxProfits.emplace(0);
        maxProfits.emplace(0);

        for (int i = 0; i < profits.size(); i++)
        {
            int temp = 0;
            while ((i < profits.size()) && (profits[i] > 0))
            {
                temp += profits[i];
                ++i;
            }

            maxProfits.emplace(temp);
            maxProfits.pop();
        }
        
        int profit = maxProfits.top();
        maxProfits.pop();
        profit += maxProfits.top();
        return profit;
    }
};

int main()
{
    vector<int> prices = {1, 2, 4, 2, 5, 7, 2, 4, 9, 0};
    Solution s;
    cout << s.maxProfit(prices);
    return 0;
}