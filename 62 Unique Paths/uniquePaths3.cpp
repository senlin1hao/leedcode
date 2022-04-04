#include <iostream>

using namespace std;

//排列组合，注意计算顺序防止溢出
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        int t = m + n - 2;
        int count = m - 1;
        long long numerator = 1; //分子
        int denominator = m - 1; //分母
        while (count--)
        {
            numerator *= t--;
            while ((denominator > 0) && (numerator % denominator == 0))
            {
                numerator /= denominator--;
            }
        }
        return numerator;
    }
};