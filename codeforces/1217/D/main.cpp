#include <bits/stdc++.h>

using namespace std;


const int maxn = 5e3+100;
int n, m;
int dd[maxn],ans[maxn];
vector <pair <int ,int> > e[maxn];
int cnt = 0;

void dfs(int u)
{
    dd[u] = 1;
    for (auto eg : e[u])
    {
        int v = eg.first;
        int w = eg.second;
        if (ans[w])
            continue;
        if (dd[v])
        {
            ans[w] = 2;
            cnt = 2;
        } else
        {
            ans[w] = 1;
            dfs(v);
        }
    }
    dd[u] = 0;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back({v, i});
    }
    memset(ans, 0, sizeof(ans));
    cnt = 1;
    for (int i = 1; i <= n; i++)
        if (!dd[i])
            dfs(i);
    cout << cnt << endl;
    for (int i = 1; i <= m; i++)
        cout << ans[i] << " ";
    return 0;
}
