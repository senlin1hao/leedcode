#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }

        if (nums.size() == 2)
        {
            return max(nums[0], nums[1]);
        }
        
        vector<int> dp1(nums.begin(), nums.end() - 1);
        vector<int> dp2(nums.begin() + 1, nums.end());

        dp1[0] = nums[0];
        dp1[1] = max(dp1[0], nums[1]);
        dp2[0] = nums[1];
        dp2[1] = max(dp2[0], nums[2]);

        for (int i = 2; i < dp1.size(); i++)
        {
            dp1[i] = max(dp1[i - 2] + nums[i], dp1[i - 1]);
        }
        for (int i = 2; i < dp2.size(); i++)
        {
            dp2[i] = max(dp2[i - 2] + nums[i + 1], dp2[i - 1]);
        }
        
        return max(dp1.back(), dp2.back());
    }
};