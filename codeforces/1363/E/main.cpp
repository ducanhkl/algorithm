#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+100;

long long cost[maxn];
long long ans = 0;
int b[maxn], c[maxn], dif[maxn];
int n;

vector <int> e[maxn];

void dfs(int u, int par)
{
    long long tmp = abs(dif[u]);
    for (auto v : e[u])
    {
        if (v == par)
        {
            continue;
        }
        cost[v] = min(cost[v], cost[u]);
        dfs(v, u);
        dif[u] += dif[v];
        tmp += abs(dif[v]);
    }
    ans += (tmp - abs(dif[u]))*cost[u];
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i] >> b[i] >> c[i];
        dif[i] = b[i] - c[i];
    }
    for (int i = 1; i < n;  i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    if (dif[1])
    {
        cout << -1;
    } else {
        cout << ans;
    }
    return 0;
}
