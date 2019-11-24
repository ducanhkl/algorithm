#include "bits/stdc++.h"

using namespace std;

const int maxn = 1e5+100;
int n;
int cnt[maxn], res[maxn];

vector <int> e[maxn];

void dfs(int u, int par)
{
    cnt[u]  = 1;
    for (auto v : e[u])
    {
        if (v == par || res[v])
            continue;
        dfs(v, u);
        cnt[u] += cnt[v];
    }
}

int findres (int u, int val)
{
    for (auto v : e[u])
    {
        if (res[v])
            continue;
        if (cnt[v] > val/2 && cnt[v] < cnt[u])
            return findres (v, val);
    }
    return u;
}

void solve(int u, int val)
{
    dfs(u, -1);
    int newu = findres(u, cnt[u]);
    res[newu] = val;
    for (auto v : e[newu])
        if (res[v] == 0)
            solve(v, val + 1);
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i  = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    solve(1, 1);
    for (int i = 1; i <= n; i++)
        cout << (char)(res[i] + 'A' - 1) << " ";
}