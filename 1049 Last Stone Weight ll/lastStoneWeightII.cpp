#include <iostream>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int sum = 0;
        for (int i : stones)
        {
            sum += i;
        }
        int target = sum / 2;
        int dp[1501];
        memset(dp, 0, sizeof(int) * 1501);

        for (int i = 0; i < stones.size(); i++)
        {
            for (int j = target; j >= stones[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return sum - 2 * dp[target];
    }
};