#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        stack<char> a, b;

        for (char chs : s)
        {
            if (chs == '#' && a.size() != 0)
                a.pop();
            else if (chs == '#' && a.size() == 0)
                continue;
            else
                a.push(chs);
        }

        for (char cht : t)
        {
            if (cht == '#' && b.size() != 0)
                b.pop();
            else if (cht == '#' && b.size() == 0)
                continue;
            else
                b.push(cht);
        }

        if (a == b)
            return true;
        else
            return false;
    }
};

void printResult(bool b)
{
    if (b == 1)
        cout << "Strings are equal" << endl;
    else
        cout << "Strings are not equal" << endl;
}
int main()
{
    Solution s;
    bool test1 = s.backspaceCompare("ab#c", "ad#c");
    bool test2 = s.backspaceCompare("ab##", "c#d#");
    bool test3 = s.backspaceCompare("a#c", "b");
    printResult(test1);
    printResult(test2);
    printResult(test3);
    return 0;
}
