#include <bits/stdc++.h>

using namespace std;

const int maxn = 1200;

int n, m;
bitset<2010> dp[maxn];

void solve()
{
    cin >> n >> m;
    for (int i = 0; i <= m + 1; i++)
    {
        dp[i].reset();
    }
    dp[1][1000] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int x;
            cin >> x;
            if (x == 1)
            {
                dp[j] <<= 1;
            }
            else
            {
                dp[j] >>= 1;
            }
            if (j + 1 <= m)
            {
                dp[j + 1] |= dp[j];
            }
        }
    }
    if (dp[m][1000])
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    cout << endl;
}

int main()
{
    // freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        solve();
    }
}