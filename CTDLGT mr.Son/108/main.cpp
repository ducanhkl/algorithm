#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n, m;
vector <int> e[200], ans;
int dd[maxn];

void reset()
{
    ans.resize(0);
    for (int i = 1; i <= n; i++)
        e[i].resize(0);
}

bool check()
{
    for (int i = 1; i <= n; i++)
        if (dd[i] == 0)
            return true;
    return false;
}

void dfs(int u)
{
    dd[u] = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (dd[v])
            continue;
        dfs(v);
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n >> m;
        reset();
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for (int i = 1; i <= n; i++)
        {
            memset(dd, 0, sizeof(dd));
            dd[i] = 1;
            if (i != 1)
                dfs(1);
            else
                dfs(2);
            if (check())
                ans.push_back(i);
        }
        cout << ans.size() << endl;
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i];
        cout << endl;
    }
    return 0;
}

