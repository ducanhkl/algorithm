#include <bits/stdc++.h>
#define maxn 101

using namespace std;


long long f[maxn][maxn], c[maxn][maxn], a[maxn];
int n,e, sl = INT_MAX, ans = INT_MAX;

void init()
{
    memset(c, 0, sizeof(c));
    for (int i = 0; i <= n; i++)
        for (int j = i+1; j <= n+1; j++)
            if ((i != 0) || (j != n+1))
        {
            if (i == 0)
                a[i] = a[j];
            if (j == n+1)
                a[j] = a[i];
            for (int k = i+1; k <= j-1; k++)
                c[i][j] += abs(2*a[k] - (a[i]+a[j]));
        }
    return;
}

void solve()
{
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            f[i][j] = INT_MAX;
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
    {
        for (int k = j-1; k <= i-1; k++)
            f[i][j] = min(f[i][j], f[k][j-1] + c[k][i]);
        if (f[i][j] + c[i][n+1] <= e)
            if (j < sl || ((j == sl) && (f[i][j] + c[i][n+1] < ans)))
        {
            sl = j;
            ans = f[i][j] + c[i][n+1];
        }
    }

}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> e;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    init();
    solve();
    cout << sl << " " << ans;
    return 0;
}
