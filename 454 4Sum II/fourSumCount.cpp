#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> nums12_map;
        for (int a : nums1)
        {
            for (int b : nums2)
            {
                nums12_map[a + b]++;
            }
        }

        int result = 0;
        for (int c : nums3)
        {
            for (int d : nums4)
            {
                if (nums12_map.find(0 - c - d) != nums12_map.end())
                {
                    result += nums12_map[0 - c - d];
                }
            }
        }
        
        return result;
    }
};