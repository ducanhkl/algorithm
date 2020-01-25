#include <bits/stdc++.h>
#define maxn 1000005

using namespace std;


vector <pair <int, long long> > e[maxn];
int n;
long long number[maxn], ans[maxn];

void dfs(int x, int u)
{
    for (int i = 0; i < e[x].size(); i++)
    {
        int v = e[x][i].first;
        long long w = e[x][i].second;
        if (v == u)
            continue;
        dfs(v, x);
        number[x] += number[v];
        ans[x] += number[v]*w + ans[v];
    }
    return;
}

void findans(int x, int u)
{
    for (int i = 0; i < e[x].size(); i++)
    {
        int v = e[x][i].first;
        long long w = e[x][i].second;
        if (v == u)
            continue;
        ans[v] = ans[x] + (n-2LL*number[v])*w;
        findans(v, x);
    }
    return;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        for (int i = 0; i < maxn; i++)
            e[i].resize(0);
        memset(ans, 0, sizeof(ans));
        memset(number, 0, sizeof(number));
        cin >> n;
        for (int i = 1; i < n; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            e[u].push_back({v, w});
            e[v].push_back({u, w});
        }
        for (int i = 1; i <= n; i++)
            number[i] = 1, ans[i] = 0;
        dfs(1, 1);
        findans(1, 1);
        for (int i = 1; i <= n; i++)
            cout << ans[i] << endl;
    }
    return 0;
}
