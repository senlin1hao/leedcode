#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> result_map;
        vector<int> result;
        for (int i = 0; i < nums.size(); i++)
        {
            if (result_map.find(nums[i]) != result_map.end())
            {
                result = {result_map.find(nums[i])->second, i};
                return result;
            }
            else
            {
                result_map.insert(pair<int, int>(target - nums[i], i));   
            }
        }
        return result;
    }
};