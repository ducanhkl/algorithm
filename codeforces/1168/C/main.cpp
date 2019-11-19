#include <bits/stdc++.h>

using namespace std;

const int maxn = 3*1e5+100, maxBit =32;
int a[maxn];
int f[maxn][40], last[maxn][40];
int n, q;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n+1; i++)
        for (int j = 0; j <= maxBit; j++)
            last[i][j] = n+1, f[i][j] = n+1;
    for (int i = n; i >= 1; i--)
        for (int j = 0; j <= maxBit; j++)
        {
            last[i][j] = last[i+1][j];
            if ((a[i] >> j)%2)
                last[i][j] = i;
        }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j <= maxBit; j++)
        {
            if (last[i][j] == i)
            {
                f[i][j] = i;
                for (int k = 0; k <= maxBit; k++)
                    f[i][k] = min(f[i][k], f[last[i+1][j]][k]);
            }
        }
    }
    for (int i = 1; i  <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        bool ans = false;
        for (int j = 0; j <= maxBit; j++)
            ans |= (f[x][j] <= y && ((a[y]>>j)%2));
        if (ans)
            cout << "Shi";
        else
            cout << "Fou";
        cout << endl;
    }
    return 0;
}
