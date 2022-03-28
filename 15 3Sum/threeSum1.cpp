#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

/*
此题使用哈希法并不十分合适，
在去重的操作中有很多细节需要注意，
很难写出没有bug的代码
*/
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                break;
            }

            //a去重
            if ((i > 0) && (nums[i] == nums[i - 1]))
            {
                continue;
            }

            unordered_set<int> set;
            for (int j = i + 1; j < nums.size(); j++)
            {
                //c去重
                if ((j > i + 2) && (nums[j] == nums[j - 1]) && (nums[j - 1] == nums[j - 2]))
                {
                    continue;
                }
                
                int b = 0 - nums[i] - nums[j];

                if (set.find(b) != set.end())
                {
                    result.push_back({nums[i], b, nums[j]});
                    set.erase(b); //b去重
                }
                else
                {
                    set.insert(nums[j]);
                }
            }
        }
        return result;
    }
};