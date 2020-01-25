#include <bits/stdc++.h>

using namespace std;

typedef pair <long long, int> pii;
const int maxn = 1e3+100;
const long long maxc = 1e15+100;
int n, m;
long long x[maxn], dp[maxn][maxn], q[maxn], s[maxn];
pii p[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    for (int i = 1; i <= m; i++)
        cin >> p[i].first >> p[i].second;
    sort (p+1, p+m+1);
    sort (x+1, x+n+1);
    for (int i = 1; i < maxn; i++)
        dp[0][i] = maxc;
    for (int i = 1; i <= m; i++)
    {
        int last = 1, sz = 0;
        q[++sz] = 0;
        for (int j = 1; j <= n; j++)
        {
            s[j] = s[j-1] + abs(p[i].first-x[j]);
            while (sz && dp[i-1][q[sz]]-s[q[sz]] >= dp[i-1][j] - s[j])
                sz--;
            q[++sz] = j;
            while (j - q[last] > p[i].second)
                last++;
            dp[i][j] = s[j] + (dp[i-1][q[last]] - s[q[last]]);
        }
    }
    if (dp[m][n] >= maxc)
        cout << -1;
    else
        cout << dp[m][n];
    return 0;
}
