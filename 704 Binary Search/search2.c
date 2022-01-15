//非递归
int search(int *nums, int numsSize, int target)
{
    int left = 0;
    int right = numsSize - 1;
    int middle;
    while (left <= right)
    {
        middle = (left + right) / 2;
        if (nums[middle] == target)
        {
            return middle;
        }
        else if (nums[middle] < target)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }

    return -1;
}