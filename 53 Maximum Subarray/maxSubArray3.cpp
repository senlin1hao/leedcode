#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

// 分治法
struct Status
{
    int leftSum;
    int rightSum;
    int middleSum;
    int sum;
};

class Solution
{
private:
    Status pushUp(Status left, Status right)
    {
        int leftSum = max(left.leftSum, left.sum + right.leftSum);
        int rightSum = max(right.rightSum, left.rightSum + right.sum);
        int middleSum = max(max(left.middleSum, right.middleSum), left.rightSum + right.leftSum);
        int sum = left.sum + right.sum;

        return Status({leftSum, rightSum, middleSum, sum});
    }

    Status getMaxStatus(vector<int>& nums, int left, int right)
    {
        if (left == right)
        {
            return Status({nums[left], nums[left], nums[left], nums[left]});
        }

        int middle = (left + right) / 2;
        Status leftStatus = getMaxStatus(nums, left, middle);
        Status rightStatus = getMaxStatus(nums, middle + 1, right);

        return pushUp(leftStatus, rightStatus);
    }

public:
    int maxSubArray(vector<int>& nums)
    {
        return getMaxStatus(nums, 0, nums.size() - 1).middleSum;
    }
};