#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e3+100;
int n;
int a[maxn], dp[maxn][maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    n = unique(a+1, a+n+1)-a-1;
    memset(dp, 0, sizeof(dp));
    for (int len = 2; len <= n; len ++)
    {
        for (int i = 1; i <= n-len+1; i++)
        {
            int j = i+len-1;
            if (a[i] == a[j])
                dp[i][j] = dp[i+1][j-1]+1;
            else
                dp[i][j] = min(dp[i+1][j], dp[i][j-1])+1;
        }
    }
    cout << dp[1][n];
    return 0;
}
