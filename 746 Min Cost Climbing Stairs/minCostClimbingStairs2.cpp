#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

//优化空间复杂度从O(n)到O(1)
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int dp0 = cost[0];
        int dp1 = cost[1];
        int dpi;
        for (int i = 2; i < cost.size(); i++)
        {
            dpi = min(dp0 + cost[i], dp1 + cost[i]);
            dp0 = dp1;
            dp1 = dpi;
        }
        return min(dp0, dp1);
    }
};