#include <bits/stdc++.h>

using namespace std;


const int maxn = 5e3+100;
int n;
int f[maxn][maxn], dp[maxn][maxn];
int a[maxn];

void init()
{
    for (int i = 1; i <= n; i++)
        dp[i][1] = f[i][1] = a[i];
    for (int len = 2; len <= n; len ++)
    {
        for (int i = 1; i+len-1 <= n; i++)
        {
            f[i][len] = f[i+1][len-1]^f[i][len-1];
            dp[i][len] = max(f[i][len], max(dp[i+1][len-1], dp[i][len-1]));
        }
    }
    return ;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    init();
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << dp[l][r-l+1] << endl;
    }
    return 0;
}
