#include <bits/stdc++.h>

using namespace std;


const int maxn = 2e5+100;
const long long mod = 1e9+7;

long long dp[maxn], tmp[maxn], ans[maxn];
vector <int> e[maxn];

int n;

void dfs1(int u)
{
    long long res = 1;
    if (e[u].size() == 0)
    {
        dp[u] = 1;
        return ;
    }
    for (auto v : e[u])
    {
        dfs1(v);
        tmp[v] = res;
        res = (res*(dp[v]+1))%mod;
    }
    res = 1;
    for (int i = e[u].size()-1; i >= 0; i--)
    {
        int v = e[u][i];
        tmp[v] = (tmp[v]*res)%mod;
        res = (res*(dp[v]+1))%mod;
    }
    dp[u]= res;
    return ;
}


void  dfs2(int u, long long res)
{
    ans[u] = (dp[u]*res)%mod;
    for (auto v : e[u])
    {
        dfs2(v, (res*tmp[v]+1)%mod);
    }
    return ;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u;
        cin >> u;
        e[u].push_back(i+1);
    }
    dfs1(1);
    dfs2(1, 1);
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}
