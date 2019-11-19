#include <bits/stdc++.h>
#define maxn 2000
#define mod 998244353

using namespace std;


int n;
long long a[maxn], dp[maxn], ans = 0, c[maxn][maxn];


void init()
{
    for (int i = 0; i < maxn; i++)
        c[i][0] = 1;
    for (int i = 1; i < maxn; i++)
        for (int j = 1; j <= i; j++)
            c[i][j] = (c[i-1][j-1] + c[i-1][j])%mod;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(dp, 0, sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    init();
    dp[n+1] = 1;
    for (int i = n; i >= 1; i--)
        if (a[i] > 0)
            for (int j = i+a[i]; j <= n; j++)
                dp[i] = (dp[j+1]*c[j-i][a[i]]%mod+dp[i])%mod;
    for (int i = 1; i <= n; i++)
        ans = (ans + dp[i])%mod;
    cout << ans;
    return 0;
}
