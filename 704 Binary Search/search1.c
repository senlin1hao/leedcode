//递归

int search(int *nums, int numsSize, int target)
{
    if (numsSize == 1)
    {
        if (*nums != target)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }

    int key1 = numsSize / 2 - 1;
    if (nums[key1] == target)
    {
        return key1;
    }
    else if (nums[key1] < target)
    {
        int key2 = search(nums + key1 + 1, numsSize - key1 - 1, target);
        if (key2 == -1)
        {
            return -1;
        }
        else
        {
            return key1 + 1 + key2;
        }
    }
    else
    {
        return search(nums, key1 + 1, target);
    }
}