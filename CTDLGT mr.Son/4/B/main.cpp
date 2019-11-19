#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    string s;
    stack <int> q;
    int test;
    cin >> test;
    while (test--)
    {
        cin >> s;
        if (s == "PUSH")
        {
            int x;
            cin >> x;
            q.push(x);
        }
        if (s == "PRINT")
        {
            if (q.size() == 0)
                cout << "NONE" << endl;
            else
                cout << q.top() << endl;
        }
        if (s == "POP")
        {
            if (q.size())
                q.pop();
        }
    }
    return 0;
}
