#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// 贪心
class Solution
{
public:
    int findLengthOfLCIS(vector<int>& nums)
    {
        int maxLength = 1;
        int tempLength = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                ++tempLength;
            }
            else
            {
                if (maxLength < tempLength)
                {
                    maxLength = tempLength;
                }
                tempLength = 1;
            }
        }

        if (maxLength < tempLength)
        {
            maxLength = tempLength;
        }

        return maxLength;
    }
};
