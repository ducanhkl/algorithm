#include <bits/stdc++.h>

using namespace std;

int n, k, h = 2;
char a[6][500];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    if (k == 3)
    if (k == n-2)
    {
        cout << "YES" << endl;
        for (int i = 1; i <= 4; i++, cout << endl)s
            for (int j = 1; j <= n; j++)
                if (i == 2 && j > 1 && j < n)
                    cout << '#';
                else cout << '.';
        return 0;
    }
    cout << "YES" << endl;
    for (int i = 1; i <= 4; i++)
        for (int j = 1; j <= n; j++)
            if (i > 1 && i < 4 && j > 1 && j < n && k != 0 )
                a[i][j] = '#', k--, h = max(h, j);
            else a[i][j] = '.';
    if (a[3][2] != '#')
        swap(a[3][2], a[2][h]), h--;
    if (a[3][2] == '#' && a[3][3] == '#')
        swap(a[3][3], a[3][h]);
    if (a[3][2] == '#' && a[3][h] != '#' && h-1 > 1)
        swap(a[2][h], a[3][h-1]);
    for (int i = 1; i <=  4; i++, cout << endl)
        for (int j = 1; j <= n; j++)
            cout << a[i][j];
    return 0;
}
