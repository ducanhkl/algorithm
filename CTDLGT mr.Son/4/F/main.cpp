#include <bits/stdc++.h>

using namespace std;

string s;

int solve()
{
    stack <char> q;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                {
                    q.push(s[i]);
                }
        else
        {
            if (s[i] == ')')
            {
                if (q.empty() || q.top() != '(')
                    return cout << "NO", 0;
                q.pop();
            }
            if (s[i] == ']')
            {
                if (q.empty() || q.top() != '[')
                    return cout << "NO", 0;
                q.pop();
            }
            if (s[i] == '}')
            {
                if (q.empty() || q.top() != '{')
                    return cout << "NO", 0;
                q.pop();
            }
        }
    cout << "YES";
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> s;
        solve();
        cout << endl;
    }
    return 0;
}
