#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3+100;
int n, m;
int a[maxn][maxn], h[maxn][maxn], v[maxn][maxn], nv[maxn], nh[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            h[i][j] = v[j][i] = a[i][j];
    for (int i = 1; i <= n; i++)
        {
            sort(h[i]+1, h[i]+m+1);
            nh[i] = unique(h[i]+1, h[i]+m+1)-h[i]-1;
        }
    for (int i = 1; i <= m; i++)
        {
            sort(v[i]+1, v[i]+n+1);
            nv[i] = unique(v[i]+1, v[i]+n+1)-v[i]-1;
        }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int aa = lower_bound(h[i]+1, h[i]+nh[i]+1, a[i][j])-h[i]-1;
            int bb = lower_bound(v[j]+1, v[j]+nv[j]+1, a[i][j])-v[j]-1;
            cout << max(aa, bb) + max(nh[i]-aa, nv[j]-bb) << " ";
        }
        cout << endl;
    }
    return 0;
}
