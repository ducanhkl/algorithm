#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+100;

int cnt[maxn], ans, p[30];
string s;

void solve()
{
    memset(cnt, 0, sizeof(cnt));
    ans = 0;
    int n = s.length();
    s = " " + s;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '0')
            cnt[i] = cnt[i-1]+1;
        else
            cnt[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int val = 0;
        for (int j = i; j >= max(i-20, 1); j--)
        {
            int oldval = val;
            val += (s[j]-'0')*p[i-j];
            if (oldval != val)
            {
                if (val <= i-j+1+cnt[j-1])
                    ans++;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    freopen("inp.txt", "r", stdin);
    int t;
    p[0] = 1;
    for (int i = 1; i <= 20; i++)
        p[i] = p[i-1]*2;
    cin >> t;
    while (t--)
    {
        cin >> s;
        solve();
    }
    return 0;
}
