#include <bits/stdc++.h>

using namespace std;

const int maxc = 1e8, maxn = 1e3+100;

int n, m, k;
vector <int> e[maxn];
int dis[maxn], mx[maxn], my[maxn], ans = 0;

bool findpath()
{
    bool check = false;
    queue <int> q;
    for (int i = 1; i <= n; i++)
        if (mx[i] == 0)
    {
        q.push(i);
        dis[i] = 0;
    } else
        dis[i] = maxc;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (auto v : e[u])
        {
            if (my[v] == 0)
            {
                check = true;
            } else
            {
                if (dis[my[v]] == maxc)
                {
                    dis[my[v]] = dis[u] + 1;
                    q.push(my[v]);
                }
            }
        }
    }
    return check;
}

bool dfs(int u)
{
    if (dis[u] == maxc)
        return false;
    for (auto v : e[u])
    {
        if (!my[v] || (dis[my[v]] == dis[u] + 1 && dfs(my[v])))
            {
                mx[u] = v;
                my[v] = u;
                return true;
            }
    }
    return false;
}

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
    }
    while (findpath())
    {
        for (int i = 1; i <= n; i++)
            if (mx[i] == 0)
                ans += dfs(i);
    }
    cout << ans;
    return 0;
}
