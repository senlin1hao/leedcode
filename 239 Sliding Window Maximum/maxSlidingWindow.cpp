#include <iostream>
#include <vector>
#include <deque>

using namespace std;

//单调队列
class MonotonousQueue
{
private:
    deque<int> numsDeque;

public:
    MonotonousQueue(){};
    ~MonotonousQueue(){};

    void push(int x)
    {
        while ((!numsDeque.empty()) && (x > numsDeque.back()))
        {
            numsDeque.pop_back();
        }

        numsDeque.push_back(x);
    }

    void pop()
    {
        numsDeque.pop_front();
    }

    int front()
    {
        return numsDeque.front();
    }
};

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        MonotonousQueue numsQueue;
        vector<int> result;

        for (int i = 0; i < k; i++)
        {
            numsQueue.push(nums[i]);
        }
        result.push_back(numsQueue.front());

        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i - k] == numsQueue.front())
            {
                numsQueue.pop();
            }

            numsQueue.push(nums[i]);
            result.push_back(numsQueue.front());
        }

        return result;
    }
};