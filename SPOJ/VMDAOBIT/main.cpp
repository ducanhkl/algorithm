#include <bits/stdc++.h>

using namespace std;

int n, m, a[1000][1000];

void daobit(int x, int y)
{
    for (int i = x; i < x+3; i++)
        for (int j = y; j < y+3; j++)
            a[i][j] = !a[i][j];
    return;
}
vector <pair <int, int> > res;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n-2; i++)
        for (int j = 1; j <= m-2; j++)
            if (a[i][j] == 1)
    {
        res.push_back({i, j});
        daobit(i, j);
    }
    for (int i = n-2; i <= n; i++)
        for (int j = m-2; j <= m; j++)
            if (a[i][j] == 1)
                return cout << -1, 0;
    cout << res.size() << endl;
    for (int i = 0; i < res.size(); i++)
        cout << res[i].first << " " << res[i].second << endl;
    return 0;
}
