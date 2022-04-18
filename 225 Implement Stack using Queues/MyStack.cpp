#include <iostream>
#include <queue>

using namespace std;


//使用1个队列
class MyStack
{
private:
    queue<int> queue1;

public:
    MyStack()
    {
    }

    void push(int x)
    {
        queue1.push(x);
    }

    int pop()
    {
        for (int i = 0; i < queue1.size() - 1; i++)
        {
            queue1.push(queue1.front());
            queue1.pop();
        }
        int result = queue1.front();
        queue1.pop();
        return result;
    }

    int top()
    {
        for (int i = 0; i < queue1.size() - 1; i++)
        {
            queue1.push(queue1.front());
            queue1.pop();
        }
        int result = queue1.front();
        queue1.push(queue1.front());
        queue1.pop();
        return result;
    }

    bool empty()
    {
        return queue1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
