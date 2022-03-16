#include <iostream>
#include <unordered_set>

using namespace std;

//建表至243，时间复杂度O(logn)，空间复杂度O(1)
//对于3位数，下一个数不可能大于243，对于4位数及以上，下一个数必比原数小
//另写程序找到所有周期，发现只有一个循环：4→16→37→58→89→145→42→20→4
//所有其他数字都在进入这个循环的链上，或者在进入1的链上
class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> unhappy_set{4, 16, 37, 58, 89, 145, 42, 20, 4};
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
                if (unhappy_set.find(m) != unhappy_set.end())
                {
                    return false;
                }
                else
                {
                    n = m;
                }
            }
        }
    }
};