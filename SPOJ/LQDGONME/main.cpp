#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define maxn 1006

using namespace std;

int a[maxn][maxn], b[maxn][maxn], dp[maxn];
int n, m, res = 0;
int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(dp, 0, sizeof(dp));
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
    {
        cin >> a[i][j];
        b[i][a[i][j]] = j;
    }
    for (int i = 1; i <= n; i++)
        for (int j = i-1; j >= 1; j--)
    {
        int check = true;
        for (int k = 2; k <= m; k++)
            if (b[k][a[1][i]] < b[k][a[1][j]])
        {
            check = false;
            break;
        }
        if (check)
            dp[a[1][i]] = max(dp[a[1][i]], dp[a[1][j]]+1), res = max(res, dp[a[1][i]]);
    }
    cout << res + 1;
    return 0;
}
