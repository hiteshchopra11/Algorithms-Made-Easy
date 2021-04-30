#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    stack<int> a, b;
    /** Push element x to the back of queue. */
    void push(int x)
    {
        a.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        if (b.empty())
        {
            while (a.empty() != true)
            {
                b.push(a.top());
                a.pop();
            }
        }
        int value = b.top();
        b.pop();
        return value;
    }

    /** Get the front element. */
    int peek()
    {
        if (b.empty())
        {
            while (a.empty() != true)
            {
                b.push(a.top());
                a.pop();
            }
        }
        return b.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        if (b.empty() && a.empty())
            return true;
        else
            return false;
    }
};
int main()
{
    MyQueue *obj = new MyQueue();
    obj->push(10);
    obj->push(20);
    obj->push(30);
    obj->push(40);
    obj->push(50);
    int popped_value = obj->pop();
    int peek_value = obj->peek();
    bool isEmpty = obj->empty();

    cout << "Latest Popped value is " << popped_value << endl;
    cout << "Value at the peek is " << peek_value << endl;
    if (isEmpty == 0)
        cout << "Result is Empty? No" << endl;
    else
        cout << "Result is Empty? Yes" << endl;

    return 0;
}
