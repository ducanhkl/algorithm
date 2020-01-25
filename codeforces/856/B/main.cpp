#include <bits/stdc++.h>

using namespace std;

const int maxn = 30;

int n, ans = 0, cnt = 0;
int link[maxn][30], dd[maxn];
vector <int> e[maxn];

void  dfs1(int u, int v)
{
    for (int x = 0; x <= 26; x++)
        if (link[u][x] && link[v][x])
        {
            dd[link[u][x]] = link[v][x];
            e[link[v][x]].push_back(link[u][x]);
            dfs1(link[u][x], link[v][x]);
        }
    return ;
}

int dfs2(int u)
{
    int res = 1;
    for (int x : e[u])
        if (dfs2(x))
            res = 0;
    if (res)
        ans ++;
    return res;
}

void add()
{
    int u = 0;
    string s;
    cin >> s;
    for (auto x : s)
    {
        int num = x-'a';
        if (link[u][num] == 0)
            link[u][num] = ++cnt;
        u = link[u][num];
    }
}

void input()
{
    cnt = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        add();
    }
}

void solve()
{
    ans = 0;
    for (int i = 0; i <= cnt; i++)
    {
        dd[i] = 0;
        e[i].resize(0);
    }
    for (int i = 0; i <= 26; i++)
        if (link[0][i])
            dfs1(link[0][i], 0);
    for (int i = 1; i <= cnt; i++)
        if (dd[i] == 0)
            dfs2(i);
    cout << ans << endl;
    for (int i = 0; i <= cnt; i++)
        for (int j = 0; j <= 26; j++)
            link[i][j] = 0;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        input();
        solve();
    }
    return 0;
}
