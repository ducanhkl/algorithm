#include <bits/stdc++.h>

using namespace std;

int n, k;
bool dp[30000];
int a[300];

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(dp, 0, sizeof(dp));
    ios_base::sync_with_stdio(false);
    cin >> k >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        for (int j = k; j >= a[i]; j--)
            dp[j] = max(dp[j], dp[j-a[i]]);
    for (int i = k; i >= 0; i--)
        if (dp[i])
            return cout << i, 0;
    return 0;
}
