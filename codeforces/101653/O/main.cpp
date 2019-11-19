#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+100;
typedef pair <double, double> pii;
int n, dp[maxn];
pii a[maxn];

bool cmp(pii x, pii y)
{
    if (x.first == y.first)
        return x.second > y.second;
    return x < y;
}

void solve()
{
    memset(dp, 0 ,sizeof(dp));
    int ans = 0;
    a[0] = {-INT_MAX, INT_MAX};
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 0; j--)
            if (a[i].second < a[j].second && a[i].first > a[j].first)
                dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
