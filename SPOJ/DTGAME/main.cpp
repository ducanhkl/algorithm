#include <bits/stdc++.h>
#define maxn 2200

using namespace std;

long long a[maxn], s[maxn], f[maxn][maxn];
int n;
int p[maxn][maxn];


int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    memset(s, 0, sizeof(s));
    memset(f, 0, sizeof(f));
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], s[i] += a[i] + s[i-1];
    for (int i = 1; i <= n; i++)
        p[i][i] = i;
    for (int len = 1; len <= n; len ++)
        for (int i = 1; i <= n-len; i++)
    {
        int j = len+i;
        for (int k = max(i, p[i][j-1]); k < j && k <= p[i+1][j]; k++)
        {
            long long res = min(f[i][k]+s[k]-s[i-1], f[k+1][j] + s[j]-s[k]);
            if (f[i][j] < res)
            {
                f[i][j] = res;
                p[i][j] = k;
            }
        }
    }
    cout << f[1][n];
    return 0;
}
