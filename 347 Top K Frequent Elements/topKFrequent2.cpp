#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

//哈希法+优先级队列（小顶堆）
class Solution
{
private:
    //注意这里需要static，小顶堆为升序排列
    static bool compare(pair<int, int> &p1, pair<int, int> &p2)
    {
        return (p1.second > p2.second);
    }

public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        /*
        decltype 类型说明符生成指定表达式的类型。在此过程当中，编译器分析表达式并获得它的类型，却不实际计算表达式的值。
        语法为：decltype(expression)
        若 expression 参数是标识符或类成员访问，则 decltype(expression) 是 expression 命名的实体的类型。若是不存在此类实体或 expression 参数命名一组重载函数，则编译器将生成错误消息。
        若 expression 参数是对一个函数或一个重载运算符函数的调用，则 decltype(expression) 是函数的返回类型。将忽略重载运算符两边的括号。
        若 expression 参数是右值，则 decltype(expression) 是 expression类型。若是 expression参数是左值，则 decltype(expression) 是对 左值引用 类型的expression。
        */
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&compare)> pri_queue;

        unordered_map<int, int> numsMap;
        for (int i : nums)
        {
            ++numsMap[i];
        }

        for (pair<int, int> p : numsMap)
        {
            if (pri_queue.size() < k)
            {
                pri_queue.push(p);
            }
            else
            {
                pri_queue.push(p);
                pri_queue.pop();
            }
        }

        vector<int> result(k);
        for (int i = k - 1; i >= 0; i--)
        {
            result[i] = pri_queue.top().first;
            pri_queue.pop();
        }
        
        return result;
    }
};

int main()
{
    vector<int> v1({1,1,1,2,2,3});
    int k = 2;
    Solution s;
    vector<int> v2 = s.topKFrequent(v1, k);
    for (int i : v2)
    {
        cout << i << " ";
    }
    return 0;
}