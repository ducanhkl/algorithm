#include <bits/stdc++.h>
#define maxn 600000

using namespace std;

vector <int> e[maxn];
int n, m, ans = 0;
int dd[maxn], sl[maxn];
map <int, int> c[maxn];

void reset()
{
    n = m = 0;
    for (int i = 0; i < maxn; i++)
        e[i].resize(0), c[i].clear();
    ans = 0;
    memset(dd, 0, sizeof(dd));
    memset(sl, 0, sizeof(sl));
}

bool check(int u)
{
    int f = 0, s = 0;
    if (dd[u] == 1 || sl[u] != 2)
        return false;
    for (int i = 0; i < e[u].size(); i++)
        if (dd[e[u][i]] == 0)
            if (f != 0)
    {
        s = e[u][i];
        break;
    }   else f = e[u][i];
    return c[f][s];
}

int remo(int u)
{
    dd[u] = 1;
    for (int i = 0; i < e[u].size(); i++)
        sl[e[u][i]] --;
    return 0;
}

void dfs(int u)
{
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (check(v))
        {
            remo(v);
            dfs(v);
        }
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t, C = 1;
    cin >> t;
    while (t--)
    {
        reset();
        cin >> n >> m;
        for (int i = 1; i <=m; i++)
            {
                int u, v;
                cin >> u >> v;
                sl[u] ++, sl[v]++;
                c[u][v] = 1;
                c[v][u] = 1;
                e[u].push_back(v);
                e[v].push_back(u);
            }
        for (int i = 1; i <= n; i++)
            if (check(i))
        {
            remo(i);
            dfs(i);
        }
        for (int i = 1; i <= n; i++)
            ans += (dd[i] == 0);
        cout << "Case #" << C++ << endl << ans << endl;
    }
    return 0;
}
