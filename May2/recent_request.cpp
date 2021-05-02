#include <bits/stdc++.h>
using namespace std;
class RecentCounter
{
public:
    queue<int> q;
    int ping(int t)
    {
        q.push(t);
        while (q.front() < (t - 3000))
            q.pop();
        return q.size();
    }
};

int main()
{
    RecentCounter *obj = new RecentCounter();
    obj->ping(1);
    obj->ping(100);
    obj->ping(3001);
    int result = obj->ping(3002);
    cout << "Number of recent requests are " << result << endl;
    return 0;
}
