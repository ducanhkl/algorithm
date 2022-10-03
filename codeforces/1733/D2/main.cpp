#include <bits/stdc++.h>

using namespace std;

const int maxn = 7000;

int d[maxn];
long long dp[maxn];
int t, n;
long long x, y;
string a, b;

void solve()
{
    t = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i-1] != b[i-1])
        {
            d[++t] = i;
        }
    }
    if (t%2)
    {
        cout << -1;
        return ;
    }
    if (x > y)
    {
        if (t == 2 &&  d[1] == d[2] - 1)
        {
            cout << min(x, 2*y);
            return ;
        }
        cout << (t/2)*y;
        return ;
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 2; i <= n; i++)
    {
        if (i%2 == 0)
        {
            dp[i] = min(dp[i-2] + (d[i] - d[i-1])*x, dp[i-1] + y);
        }
        else
        {
            dp[i] = min(dp[i-2] + (d[i] - d[i-1])*x, dp[i-1]);
        }
    }
    cout << dp[t];
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n >> x >> y >> a >> b;
        solve();
        cout << endl;
    }
    return 0;
}
