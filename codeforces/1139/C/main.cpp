#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9+7;
const int maxn = 1e5+100;
typedef pair <int, int> pii;
int n, k;
long long ans = 0;
vector <pii> e[maxn];
vector  <int> v[maxn];
int cnt = 0, ufr[maxn], dd[maxn];


void dfs(int u)
{
    v[cnt].push_back(u);
    ufr[u] = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i].first;
        int l = e[u][i].second;
        if (ufr[v] || l == 1)
            continue;
        dfs(v);
    }
}

long long fast_pow(long long x, long long y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    long long res = fast_pow(x, y/2);
    res=res*res%mod;
    if (y%2)
        return res*x%mod;
    else
        return res;
}

long long calc(long long x, long long y)
{
    return fast_pow(y, x);
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(dd, 0, sizeof(dd));
    memset(ufr, 0, sizeof(ufr));
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i < n; i++)
    {
        int u, v, x;
        cin >> u >> v >> x;
        e[u].push_back({v, x});
        e[v].push_back({u, x});
        if (x == 0)
            dd[u] = 1;
    }
    for (int i = 1; i <= n; i++)
        if (ufr[i] == 0 && dd[i])
            cnt++, dfs(i);
    ans = (calc(k, n)-n+mod)%mod;
    for (int i = 1; i <= cnt; i++)
        ans = (ans - calc(k, v[i].size())+v[i].size() + mod)%mod;
    cout << ans;
    return 0;
}
