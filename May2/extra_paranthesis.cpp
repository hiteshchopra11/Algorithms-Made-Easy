#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minAddToMakeValid(string S)
    {
        stack<char> s;
        int ans = 0;
        for (char ch : S)
        {
            if (ch == '(')
            {
                s.push(ch);
                ans++;
            }
            else if (s.size() > 0 && ch == ')' && s.top() == '(')
            {
                s.pop();
                ans--;
            }
            else if (ch == ')' && s.size() == 0 || ch == ')' && s.top() == ')')
                ans++;
        }
        return ans;
    }
};

int main()
{
    Solution s;

    int answer1 = s.minAddToMakeValid("())");
    int answer2 = s.minAddToMakeValid("(((");
    int answer3 = s.minAddToMakeValid("()");
    int answer4 = s.minAddToMakeValid("()))((");

    cout << "()) requires " << answer1 << " extra paranthesis!" << endl;
    cout << "((( requires " << answer2 << " extra paranthesis!" << endl;
    cout << "() requires " << answer3 << " extra paranthesis!" << endl;
    cout << "()))(( requires " << answer4 << " extra paranthesis!" << endl;
}
