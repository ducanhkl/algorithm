#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;

class node {
public:
    int minn = INT_MAX, maxx = 0;
    void upd()
    {
        minn = INT_MAX, maxx = 0;
    }
    void upd(node &x)
    {
        minn = min(minn, x.minn);
        maxx = max(maxx, x.maxx);
    }
} c[maxn], res[maxn];

typedef pair<int, int> pii;

vector <tuple <int, int, int> >task_list[maxn];
vector <pii> e[maxn], qu[maxn];

int n;
int root[maxn], ufr[maxn];

void init()
{

}

int get_root(int u)
{
    if (root[u] == 0)
    {
        return u;
    }
    int tmp = root[u];
    root[u] = get_root(root[u]);
    c[u].upd(c[tmp]);
    return root[u];
}

void dfs(int u, int par)
{
    for (auto edge: e[u])
    {
        int v, w;
        tie(v, w) = edge;
        if (v == par)
        {
            continue;
        }
        dfs(v, u);
        root[v] = u;
        c[v].maxx = w;
        c[v].minn = w;
    }
    ufr[u] = 1;
    for (int i  = 0; i < qu[u].size(); i++)
    {
        int v = qu[u][i].first;
        if (ufr[v] == 0)
        {
            continue;
        }
        int t = qu[u][i].second;
        task_list[get_root(v)].push_back({u, v, t});
    }
    for (int i = 0; i < task_list[u].size(); i++)
    {
        int f, s, pos;
        tie(f, s, pos) = task_list[u][i];
        get_root(f);
        get_root(s);
        auto t = c[f];
        t.upd(c[s]);
        res[pos] = t;
    }
}

int main()
{
    // freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        e[u].push_back({v, c});
        e[v].push_back({u, c});
    }
    init();
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        qu[u].push_back({v, i});
        qu[v].push_back({u, i});
    }
    dfs(1, 0);
    for (int i = 1; i <= q; i++)
    {
        cout << res[i].minn << " " << res[i].maxx << endl;
    }
    return 0;
}
