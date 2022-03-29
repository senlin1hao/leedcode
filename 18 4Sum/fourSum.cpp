#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        if (nums.size() < 4)
        {
            return result;
        }

        for (int i = 0; i < nums.size() - 3; i++)
        {
            // a去重
            if ((i > 0) && (nums[i] == nums[i - 1]))
            {
                continue;
            }

            for (int j = i + 1; j < nums.size() - 2; j++)
            {
                // b去重
                if ((j > i + 1) && (nums[j] == nums[j - 1]))
                {
                    continue;
                }

                int left = j + 1;
                int right = nums.size() - 1;

                while (left < right)
                {
                    //(nums[i] + nums[j] + nums[left] + nums[right]) < target会溢出int范围
                    if ((nums[i] + nums[j]) < (target - nums[left] - nums[right]))
                    {
                        ++left;

                        // c去重
                        while ((left < right) && (nums[left] == nums[left - 1]))
                        {
                            ++left;
                        }
                    }
                    //(nums[i] + nums[j] + nums[left] + nums[right]) > target会溢出int范围
                    else if ((nums[i] + nums[j]) > (target - nums[left] - nums[right]))
                    {
                        --right;

                        // d去重
                        while ((left < right) && (nums[right] == nums[right + 1]))
                        {
                            --right;
                        }
                    }
                    else
                    {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});

                        ++left;
                        --right;

                        // c去重
                        while ((left < right) && (nums[left] == nums[left - 1]))
                        {
                            ++left;
                        }

                        // d去重
                        while ((left < right) && (nums[right] == nums[right + 1]))
                        {
                            --right;
                        }
                    }
                }
            }
        }

        return result;
    }
};