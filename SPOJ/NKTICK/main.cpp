#include <bits/stdc++.h>
#define maxn 60040

using namespace std;

int n;
int a[maxn], b[maxn], dp[maxn];

int main()
{
    memset(dp, 0, sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 1; j < n; j++)
        cin >> b[j];
    dp[1] = a[1];
    for (int i = 2; i <= n; i++)
        dp[i] = min(dp[i-1]+a[i], dp[i-2]+b[i-1]);
    cout << dp[n];
    return 0;
}
