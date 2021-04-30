#include <bits/stdc++.h>

using namespace std;

class MyStack
{
public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    queue<int> q1, q2;

    /** Push element x onto stack. */
    void push(int x)
    {
        q2.push(x);

        // Push all the remaining
        // elements in q1 to q2.
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap both queues
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        if (q1.empty())
            return -1;
        int temp = q1.front();
        q1.pop();
        return temp;
    }

    /** Get the top element. */
    int top()
    {
        if (q1.empty())
            return -1;
        return q1.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        if (q1.empty() == true && q2.empty() == true)
            return true;
        else
            return false;
    }
};

// Driver code
int main()
{
    MyStack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    return 0;
}
