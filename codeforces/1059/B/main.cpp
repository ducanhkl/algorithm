#include <iostream>
#define maxn 1004

using namespace std;

int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int a[maxn][maxn], b[maxn][maxn];
int n, m;

void check(int x, int y)
{
        for (int i = 0; i < 8; i++)
            if (!(x+dx[i] > 0 && y + dy[i] > 0 && x+dx[i] <= n && y+dy[i] <= m && (a[x+dx[i]][y+dy[i]]==1)))
                return;
    for (int i = 0; i < 8; i++)
        b[x+dx[i]][y+dy[i]] = 1;
    return;
}
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
        else
            a[i][j] = 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
                    check(i, j);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] != b[i][j])
                return cout << "NO", 0;
    cout << "YES";
    return 0;
}
