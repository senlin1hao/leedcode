#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

//数学技巧
/*
任何正整数都可以拆分成不超过4个数的平方和 ---> 答案只可能是1,2,3,4
如果一个数最少可以拆成4个数的平方和，则这个数还满足 n = (4^a)*(8b+7) ---> 因此可以先看这个数是否满足上述公式，如果不满足，答案就是1,2,3了
如果这个数本来就是某个数的平方，那么答案就是1，否则答案就只剩2,3了
如果答案是2，即n=a^2+b^2，那么我们可以枚举a，来验证，如果验证通过则答案是2
只能是3
*/
class Solution
{
public:
    //判断是否为完全平方数
    bool isPerfectSquare(int x)
    {
        int y = sqrt(x);
        return y * y == x;
    }

    //判断是否能表示为 4^k*(8m+7)
    bool checkAnswer4(int x)
    {
        while (x % 4 == 0)
        {
            x /= 4;
        }
        return x % 8 == 7;
    }

    int numSquares(int n)
    {
        if (isPerfectSquare(n))
        {
            return 1;
        }
        if (checkAnswer4(n))
        {
            return 4;
        }
        for (int i = 1; i * i <= n / 2; i++)
        {
            int j = n - i * i;
            if (isPerfectSquare(j))
            {
                return 2;
            }
        }
        return 3;
    }
};