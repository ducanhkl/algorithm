#include <bits/stdc++.h>

using namespace std;


const int maxn = 120, maxm = 10200;
int n;
int dp[maxn][maxm+100], g[maxn][maxm+100], cnt[maxm];
set <int> s;
int a[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], cnt[a[i]] ++;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        s.insert(a[i]);
        for (int j = i; j >= 0; j--)
        {
            for (int k = 0; k < maxm; k++)
            {
                if (dp[j][k] == 0)
                    continue;
                dp[j+1][k+a[i]] = 1;
                if (((k+a[i])%(j+1) == 0) && (a[i]*(j+1) != (k+a[i])))
                    g[j+1][k+a[i]] = 1;
            }
        }
    }
    if (s.size() == 2)
    {
        cout << n;
        return 0;
    }
    int ans = 0;
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 0; j <= cnt[i]; j++)
        {
            if (g[j][i*j] == 1)
                break;
            ans = max(ans, j);
            // debug cout << i << " " << j << endl;
        }
    }
    cout << ans;
    return 0;
}
