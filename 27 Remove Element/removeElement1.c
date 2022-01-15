//用末尾值值覆盖，改变了元素的相对位置
int removeElement(int *nums, int numsSize, int val)
{
    int valCount = 0;

    for (int i = 0; i < numsSize - valCount; i++)
    {
        if (nums[i] == val)
        {
            int right = numsSize - (++valCount);
            while ((right > i) && (nums[right] == val))
            {
                --right;
                ++valCount;
            }
            nums[i] = nums[right];
        }
    }
    return numsSize - valCount;
}