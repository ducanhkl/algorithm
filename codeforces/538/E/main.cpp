#include <bits/stdc++.h>

using namespace std;


const int maxn = 100;

int n;
vector <int> e[maxn];
int dp1[maxn], dp2[maxn];

void dfs(int u)
{
    if (e[u].size() == 0)
    {
        dp1[u] = dp2[u] = 1;
        return ;
    }
    dp1[u] = INT_MAX;
    dp2[u] = 0;
    for (auto v : e[u])
    {
        dfs(v);
        dp1[u] = min(dp1[u], dp2[v]);
        dp2[u] = dp2[u] + dp1[v];
    }
}

int main()
{
    freopen("inp.txt", "r", stdin);
    int m = 0;
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++)
        {
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
        }
    for (int i = 1; i <= n; i++)
        if (e[i].size() == 0)
            m ++;
    dfs(1);
y    cout << m+1-dp1[1] << " " << dp2[1];
    return 0;
}
