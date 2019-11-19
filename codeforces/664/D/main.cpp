#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e5+100;

int n, m;
int ufr[maxn], g[maxn];
vector <int> v1, v2;
vector < pair<int, char> > e[maxn];
int bad = 0;

void dfs(int u, int c, int color)
{
    ufr[u] = 1;
    g[u] = c;
    if (c == 0)
        v1.push_back(u);
    else
        v2.push_back(u);
    for (auto eg : e[u])
    {
        int v = eg.first;
        char ch = eg.second;
        int newg;
        if (ch == color)
            newg = c;
        else
            newg = c^1;
        if (ufr[v])
        {
            if (newg != g[v])
                bad = 1;
            continue;
        }
        dfs(v, newg, color);
    }
}

vector <int> getans(char color)
{
    memset(ufr, 0, sizeof(ufr));
    memset(g, 0, sizeof(g));
    vector <int> r;
    for (int i = 1; i <= n; i++)
    {
        if (ufr[i] == 1)
            continue;
        bad = 0;
        v1.resize(0);
        v2.resize(0);
        dfs(i, 0, color);
        if (bad)
        {
            v1.resize(0);
            v1.push_back(-1);
            return v1;
        } else
        {
            if (v1.size() > v2.size())
                swap(v1, v2);
            for (auto v : v1)
                r.push_back(v);
        }
    }
    return r;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        char c;
        cin >>u >> v >> c;
        e[u].push_back({v, c});
        e[v].push_back({u, c});
    }
    auto r1 = getans('B');
    auto r2 = getans('R');
    if (r1.empty() || r2.empty())
    {
        cout << 0;
        return 0;
    }
    if (r1[0] == -1 && r2[0] == -1)
    {
        cout << -1;
        return 0;
    }
    auto res = r1;
    if (r1[0] == -1)
        res = r2;
    else
        if (r2[0] != -1 && r2.size() < r1.size())
            res = r2;
    cout << res.size() << endl;
    for (auto v : res)
        cout << v << " ";
    return 0;
}
