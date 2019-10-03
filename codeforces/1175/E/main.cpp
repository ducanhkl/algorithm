#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5+100;
int n, m;
int jum[30][maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    memset(jum, 0, sizeof(jum));
    for (int i = 1; i <= n; i++)
        jum[0][i] = i;
    for (int i = 1; i<= n; i++)
        {
            int x, y;
            cin >> x>> y;
            jum[0][x] = max(jum[0][x], y);
        }
    for (int x = 1; x < maxn; x++)
        jum[0][x] = max(jum[0][x], jum[0][x-1]);
    for (int i = 1; i < 23; i++)
        for (int j = 0; j < maxn; j++)
            jum[i][j] = jum[i-1][jum[i-1][j]];
    for (int i = 1; i <= m; i++)
    {
        int x, y, ans = 0;
        cin >> x >>y;
        for (int j = 22; j >= 0; j --)
            if (jum[j][x] < y)
                ans += (1<<j), x = jum[j][x];
        if (jum[0][x] >= y)
            cout << ans+1;
        else
            cout << -1;
        cout << endl;
    }
    return 0;
}
