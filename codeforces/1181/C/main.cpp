#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3+!00;
long long f[maxn][maxn], res[maxn][maxn], ans = 0;
int n, m;
char a[maxn][maxn];



int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(f, 0, sizeof(f));
    memset(res, 0, sizeof(res));
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j ++)
            {
                cin >> a[i][j];
                if (i == 1 || a[i][j] != a[i-1][j])
                    f[i][j] = 1;
                else
                    f[i][j] = f[i-1][j]+1;
            }
    for (int i = 1; i <= n; i++)
    {
        int sum = 0 ;
        for (int j = 1; j <= m; j++)
        {
            int last = f[i][j];
            if (last == f[i-last][j] && last <= f[i-2*last][j])
            {
                res[i][j] = 1;
                if (sum == last && a[i][j-1] == a[i][j] && a[i-last][j-1] == a[i-last][j] && a[i-2*last][j-1] == a[i-2*last][j])
                    res[i][j] += res[i][j-1];
                sum = last;
                ans += res[i][j];

            } else
            {
                sum = 0;
            }
        }
    }
    cout << ans;
    return 0;
}
