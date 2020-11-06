#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
const long long mod = 1e9+7;

int n, m;
long long cnt[maxn], p[maxn];
vector <long long> eg;
vector <int> e[maxn];


int dfs(int u, int par)
{
    cnt[u] = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (v == par)
            continue;
        dfs(v, u);
        cnt[u] += cnt[v];

    }
    eg.push_back(cnt[u]*(n - cnt[u]));
    return 0;
}

void solve()
{
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        e[i].resize(0);
    eg.resize(0);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 0);
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> p[i];
    sort (p+1, p+m+1);
    for (int i = m; i > n-1; i --)
        p[i-1] = (p[i]*p[i-1])%mod;
    m = min(m, n-1);
    for (int i = 1; i <= m/2; i++)
        swap(p[i], p[m-i+1]);
    for (int i = m+1; i < n; i++)
        p[i] = 1;
    sort(eg.begin(), eg.end(), greater<long long>());
    for (int i = 0; i < n-1;  i++)
    {
        ans = (ans + (p[i+1]*eg[i])%mod)%mod;
    }
    cout << ans << endl;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}
