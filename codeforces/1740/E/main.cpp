#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;

int n;
int p[maxn], dp[maxn], h[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    h[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        cin >> p[i];
        h[i] = 1;
    }
    for (int i = n; i >= 1; i--)
    {
        dp[i] = max(dp[i], h[i]);
        dp[p[i]] += dp[i];
        h[p[i]] = max(h[p[i]], h[i]+1);
    }
    cout << dp[1];
    return 0;
}
