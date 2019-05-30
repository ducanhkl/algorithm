#include <bits/stdc++.h>

using namespace std;

const int maxn = 200;
long long dp[200][200][200];
int n;
char s[maxn];
int a[maxn];

long long calc(int l, int r, int pre)
{
    if (l > r)
        return 0;
    if (l == r)
        return a[pre];
    if (dp[l][r][pre])
        return dp[l][r][pre];
    long long &ans = dp[l][r][pre];
    ans = a[pre] + calc(l+1, r, 1);
    for (int i = l+1; i <= r; i++)
        if (s[l] == s[i])
            ans = max(ans, calc(l+1, i-1, 1) + calc(i, r, pre+1));
    return ans;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cout << calc(1, n, 1);
    return 0;
}
