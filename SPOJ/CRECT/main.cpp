#include <bits/stdc++.h>
#define maxn 500

using namespace std;


long long f[maxn][maxn], d[maxn][maxn], p[maxn], ans = 0;
char s[maxn][maxn];
int n, m;

long long calc(char x, char y, char z)
{
    long long res = 0;
    memset(f, 0, sizeof(f));
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (s[i][j] == x || s[i][j] == y || s[i][j] == z)
                f[i][j] = f[i-1][j] + 1;
            else f[i][j] = 0;
    for (int i = 1; i <= m; i++)
    {
        int t = 0, q[maxn];
        memset(q, 0, sizeof(q));
        for (int  j = 1; j <= n; j++)
        {
            while (f[i][j] <= f[i][q[t]] && t > 0)
                t--;
            if (t == 0)
                d[i][j] = f[i][j] * j;
            else d[i][j] = f[i][j]*(j-q[t]) + d[i][q[t]];
            q[++t] = j;
            res += d[i][j];
        }
    }
    return res;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
    {
        char x;
        cin >> x;
        s[i][j] = x;
    }
    for (int i = 'A'; i <= 'E'; i++)
        p[i] = calc(i, i, i);
    for (int i = 'A'; i <= 'E'; i++)
        for (int j = i+1; j <= 'E'; j++)
            for (int k = j+1; k <= 'E'; k++)
                ans += calc(i, j, k) - calc(i ,i, j) - calc(j, j, k) - calc(i, i, k) + p[i] + p[j] + p[k];
    cout << ans;
    return 0;
}
