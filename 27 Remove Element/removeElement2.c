//双指针法，不改变元素的相对位置
int removeElement(int *nums, int numsSize, int val)
{
    int *fast = nums;
    int *slow = nums;
    int valCount = 0;
    while (fast <= nums + numsSize - 1)
    {
        if (*fast == val)
        {
            ++fast;
            ++valCount;
            continue;
        }
        *slow = *fast;
        ++slow;
        ++fast;
    }
    return numsSize - valCount;
}