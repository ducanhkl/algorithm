#include <bits/stdc++.h>

using namespace std;


const int maxn = 200;
const int maxc = 1e9;

int n;
long long a[maxn][maxn], dd[maxn];
long long ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 0 && i != j)
                    a[i][j] = maxc;
            }
    for (int i = 1; i <= n; i++)
        a[0][i] = a[i][0] = maxc;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
            }
        }
    }
    int last = 1;
    dd[last] = 1;
    for (int i = 2; i < n; i++)
    {
        int v = 0;
        for (int j = 1; j <= n; j++)
        {
            if (dd[j] == 0 && a[last][j] < a[last][v] && j != n)
                v = j;
        }
        dd[v] = 1;
        ans += a[last][v];
        last = v;
    }
    ans += a[last][n];
    cout << ans;
    return 0;
}
