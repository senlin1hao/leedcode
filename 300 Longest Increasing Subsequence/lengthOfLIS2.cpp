#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// 贪心 + 二分查找，时间复杂度O(nlog(n))
class Solution
{
public:
    int lengthOfLIS(vector<int>& nums)
    {
        int maxLength = 1;
        vector<int> increasingArray(nums.size(), 0);

        increasingArray[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > increasingArray[maxLength - 1])
            {
                increasingArray[maxLength] = nums[i];
                ++maxLength;
            }
            else
            {
                int left = 0;
                int right = maxLength - 1;
                int middle = (left + right) / 2;

                while (left <= right)
                {
                    if (nums[i] == increasingArray[middle])
                    {
                        break;
                    }
                    else if (nums[i] < increasingArray[middle])
                    {
                        right = middle - 1;
                        middle = (left + right + 1) / 2;
                    }
                    else // nums[i] > increasingArray[middle]
                    {
                        left = middle + 1;
                        middle = (left + right + 1) / 2;
                    }
                }
                increasingArray[middle] = nums[i];
            }
        }

        return maxLength;
    }
};
