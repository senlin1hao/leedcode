#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return false;
        }

        int sum = 0;
        for (int i : nums)
        {
            sum += i;
        }
        if (sum % 2)
        {
            return false;
        }

        sum /= 2;
        vector<int> dp(10001, 0);
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = sum; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        if (dp[sum] == sum)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};