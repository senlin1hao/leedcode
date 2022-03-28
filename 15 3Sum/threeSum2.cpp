#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
双指针法，比哈希法高效。
题1.两数之和不能使用双指针法，其要求返回的是索引下标，
此方法需排序，下标会改变。
*/
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        int i = 0;

        while (i < nums.size())
        {
            if (nums[i] > 0)
            {
                break;
            }

            // a去重
            if ((i > 0) && (nums[i] == nums[i - 1]))
            {
                ++i;
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                if ((nums[i] + nums[left] + nums[right]) < 0)
                {
                    ++left;

                    // b去重
                    while ((left < right) && (nums[left]) == nums[left - 1])
                    {
                        ++left;
                    }
                }
                else if ((nums[i] + nums[left] + nums[right]) > 0)
                {
                    --right;

                    // c去重
                    while ((left < right) && (nums[right] == nums[right + 1]))
                    {
                        --right;
                    }
                }
                else
                {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // b去重
                    while ((left < right) && (nums[left] == nums[left + 1]))
                    {
                        ++left;
                    }

                    // c去重
                    while ((left < right) && (nums[right] == nums[right - 1]))
                    {
                        --right;
                    }

                    ++left;
                    --right;
                }
            }

            ++i;
        }

        return result;
    }
};