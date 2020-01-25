#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int n;
int dd[maxn][3], color[maxn];
vector <int> e[maxn];

void dfs(int u, int c)
{
    if (color[u])
        return;
    color[u] = c;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        dfs(v, 3-c);
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x;
        for (int j = 1; j <= 2; j++)
        {
            cin >> x;
            if (dd[x][j])
            {
                e[dd[x][j]].push_back(i);
                e[i].push_back(dd[x][j]);
                dd[x][j] = 0;
            }
            else
                dd[x][j] = i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(i, 1);
        if (color[i] == 1)
            cout << "b";
        else cout << "r";
    }
    return 0;
}
