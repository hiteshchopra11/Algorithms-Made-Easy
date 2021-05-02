#include <bits/stdc++.h>
using namespace std;
class CustomStack
{
public:
    int size, top;
    int *stack;
    CustomStack(int maxSize)
    {
        size = maxSize;
        stack = new int[size];
        top = -1;
    }

    void push(int x)
    {
        if (top >= (size - 1))
            return;
        top++;
        stack[top] = x;
    }

    int pop()
    {
        if (top <= -1)
            return -1;
        int temp = stack[top];
        top--;
        return temp;
    }

    void increment(int k, int val)
    {
        int min;
        if (top <= (k - 1))
            min = top;
        else
            min = k - 1;

        for (int i = 0; i <= min; i++)
            stack[i] = stack[i] + val;
    }

    void display()
    {
        cout << "Current stack is -->  ";
        for (int i = 0; i <= top; i++)
            cout << stack[i] << " ";
        cout << endl;
    }
};
int main()
{
    int maxSize = 100;
    CustomStack *obj = new CustomStack(maxSize);
    obj->push(10);
    obj->push(20);
    obj->push(30);
    obj->display();
    int pop1 = obj->pop();
    cout << "Popped element is " << pop1 << endl;
    obj->display();
    obj->push(40);
    obj->push(50);
    int pop2 = obj->pop();
    cout << "Popped element is " << pop2 << endl;
    obj->increment(3, 20);
    obj->display();
    return 0;
}
