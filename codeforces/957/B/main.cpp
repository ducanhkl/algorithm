#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[200][200], b[200][200];
int r[200], c[200];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
    {
        char x;
        cin >> x;
        if (x == '#')
            a[i][j] = 1;
        else a[i][j] = 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = i+1; k <= n; k++)
                for (int h = j+1; h <= m; h++)
                    if (a[i][j] + a[i][h] + a[k][j] + a[k][h] == 3)
                        return cout << "NO", 0;
    cout << "YES";
    return 0;
}
