#include <bits/stdc++.h>

using namespace std;

const long long maxn = 1200, mod = 2520;
int n;
int k[maxn], dp[maxn][3000], d[maxn], deep = 0;
vector <int> e[maxn];

int dfs(int u, int w)
{
    if (dp[u][w] > 0)
        return dp[u][w];
    if (dp[u][w] < 0)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (d[i] <= dp[u][w])
                cnt++;
        return (dp[u][w] = cnt);
    }
    dp[u][w] = d[u] = --deep;
    int ww = (((w+k[u])%mod+mod)%(int)e[u].size());
    dp[u][w] = dfs(e[u][ww], ((w+k[u])%mod+mod)%mod);
    return dp[u][w];
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> k[i], k[i] %= mod;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        for (int j = 1; j <= num; j++)
        {
            int u;
            cin >> u;
            e[i].push_back(u);
        }
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << dfs(u, v%mod) << endl;
    }
    return 0;
}
