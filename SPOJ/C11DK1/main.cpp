#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define maxn 1000006

using namespace std;

int a[maxn];
pii b[maxn];
int n, m;
ll dp[maxn];
ll d[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++)
        dp[i] = LONG_LONG_MAX;
    dp[0] = 0;
    for (int i = 1; i <= m; i++)
        {
            cin >> b[i].first >> b[i].second;
            d[b[i].second] = max(d[b[i].second], b[i].first);
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 1000; j++)
            if (d[j] != 0)
    {
        int u = lower_bound(a+1, a+i+1, a[i] - 2*d[j]) - a;
        dp[i] = min(dp[i], dp[u-1]+j);
    }
    cout << dp[n];
    return 0;
}
