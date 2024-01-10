#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// 滑动窗口
class Solution
{
private:
    int getMaxLength(vector<int>& nums1, vector<int>& nums2, int position1, int position2, int length)
    {
        int maxLength = 0;
        int tempLength = 0;

        for (int i = 0; i < length; i++)
        {
            if (nums1[position1 + i] == nums2[position2 + i])
            {
                ++tempLength;
            }
            else
            {
                tempLength = 0;
            }

            if (tempLength > maxLength)
            {
                maxLength = tempLength;
            }
        }

        return maxLength;
    }

public:
    int findLength(vector<int>& nums1, vector<int>& nums2)
    {
        int maxLength = 0;

        // nums1首元素依次对齐nums2
        for (int i = 0; i < nums2.size(); i++)
        {
            int length = min(nums1.size(), nums2.size() - i);
            if (length <= maxLength)
            {
                break;
            }

            int tempLength = getMaxLength(nums1, nums2, 0, i, length);
            if (tempLength > maxLength)
            {
                maxLength = tempLength;
            }
        }

        // nums2首元素依次对齐nums1
        for (int i = 0; i < nums1.size(); i++)
        {
            int length = min(nums2.size(), nums1.size() - i);
            if (length <= maxLength)
            {
                break;
            }

            int tempLength = getMaxLength(nums1, nums2, i, 0, length);
            if (tempLength > maxLength)
            {
                maxLength = tempLength;
            }
        }

        return maxLength;
    }
};
