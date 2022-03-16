#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> nums1_set(nums1.begin(), nums1.end());
        unordered_set<int> result_set;
        /*
        C++11新特性，等价于以下：
        for (int i = 0; i < nums2.size(); i++)
        {
            if (nums1_set.find(nums2[i]) != nums1_set.end())
            {
                result_set.insert(nums2[i]);
            }
        }
        */
       for (int num : nums2)
       {
           if (nums1_set.find(num) != nums1_set.end())
           {
               result_set.insert(num);
           }
       }
       
        vector<int> result(result_set.begin(), result_set.end());
        return result;
    }
};