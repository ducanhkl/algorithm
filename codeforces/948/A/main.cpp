#include <bits/stdc++.h>

using namespace std;

int r, c;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int a[1000][1000];
char q[] = {'.', 'S', 'W', 'D'};

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(a, 0, sizeof(a));
    ios_base::sync_with_stdio(false);
    cin >> r >> c;
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
    {
        char x;
        cin >> x;
        if (x == '.')
            a[i][j] = 0;
        if (x == 'S')
            a[i][j] = 1;
        if (x == 'W')
            a[i][j] = 2;
    }
    for (int i = 1; i <= r; i++)
        for (int j = 1; j <= c; j++)
            if (a[i][j] == 1)
                for (int k = 0; k < 4; k++)
            {
                int x = i+dx[k];
                int y = j+dy[k];
                if (a[x][y] == 2)
                    return cout << "NO", 0;
                if (a[x][y] != 1)
                    a[x][y] = 3;
            }
    cout << "YES" << endl;
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
            cout << q[a[i][j]];
        cout << endl;
    }
    return 0;
}
