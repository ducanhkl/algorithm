#include <bits/stdc++.h>

using namespace std;

int getPriority(char x)
{
    if (x == '*' || x == '/')
        return 2;
    if (x == '+' || x == '-')
        return 1;
    else
        return 0;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        stack <char> q;
        string s, ans;
        cin >> s;
        for (int i = 0; i < s.length(); i++)
        {
            if (!(s[i] >= 'a' && s[i] <= 'z'))
            {
                if (s[i] == ')')
                {
                    while (q.top() != '(')
                            ans += q.top(), q.pop();
                    q.pop();
                    continue;
                }
                if (s[i] == '(')
                {
                    q.push(s[i]);
                    continue;
                }
                if (q.size() && getPriority(s[i]) < getPriority(q.top()))
                {
                    ans += q.top();
                    q.pop();
                }
                q.push(s[i]);
            }
            else
                ans += s[i];
        }
        while (q.size())
            ans += q.top(), q.pop();
        cout << ans << endl;
    }
    return 0;
}
