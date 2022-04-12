#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        int count = 0;
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;

        //注意是组合问题，应先遍历物品再遍历背包容量
        for (int coin : coins)
        {
            for (int i = coin; i < amount; i++)
            {
                dp[i] += dp[i - coin];
            }
        }
        
        return dp[amount];
    }
};