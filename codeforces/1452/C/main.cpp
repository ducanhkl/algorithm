#include <bits/stdc++.h>

using namespace std;


void solve(string s)
{
    int sl1 = 0, sl2 = 0, ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            sl1 ++;
        }
        if (s[i] == '[')
        {
            sl2 ++;
        }
        if (s[i] == ')')
        {
            if (sl1 >= 1)
            {
                ans ++;
                sl1 --;
            }
        }
        if (s[i] == ']')
        {
            if (sl2 >= 1)
            {
                ans++;
                sl2 --;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}
