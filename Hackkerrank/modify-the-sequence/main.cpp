#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e6;
const int maxc = 1e9+100;
int n;
int a[maxn], dp[maxn];
int ans = 0;

// tim day con tang dai nhat

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1;i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        a[i] -= i;
    for (int i = 0; i <= n; i++)
        dp[i] = maxc;
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] < 0)
            continue;
        int pos = upper_bound(dp, dp+n+1, a[i]) - dp;
        dp[pos] = a[i];
    }
    for (int i = 1; i <= n; i++)
        if (dp[i] < maxc)
            ans = max(ans, i);
    cout << n - ans;
    return 0;
}
