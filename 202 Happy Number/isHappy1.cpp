#include <iostream>
#include <unordered_set>

using namespace std;


//哈希查找是否已进入无限循环，时间、空间复杂度均为O(logn)
class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> sum_set;
        while (true)
        {
            if (n == 1)
            {
                return true;
            }
            else
            {
                int m = 0;
                while (n > 0)
                {
                    m += (n % 10) * (n % 10);
                    n /= 10;
                }
                if (sum_set.find(m) != sum_set.end())
                {
                    return false;
                }
                else
                {
                    sum_set.insert(m);
                    n = m;
                }
            }
        }
    }
};