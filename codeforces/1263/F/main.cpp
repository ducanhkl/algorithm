#include <bits/stdc++.h>

using namespace std;


const int maxn = 2e3+100;
typedef pair <int, int> pii;

int n;
int sz[maxn], mn[maxn], mx[maxn];
vector <pii> seg[maxn];
vector <int> e[maxn];
int dp[maxn];
int ans = 0;

void dfs(int u, int p)
{
    if (p == 0)
        sz[u] = 0;
    else
        sz[u] = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        dfs(v,u);
        if (mx[v] != 0)
        {
            mx[u] = max(mx[u], mx[v]);
            mn[u] = min(mn[u], mn[v]);
            sz[u] += sz[v];
        }
    }
    if (mx[u] == 0)
    {
        ans ++;
        return ;
    }
    seg[mx[u]].push_back({ mn[u], sz[u]});
}


void input()
{
    int a;
    cin >> a;
    for (int i = 1; i <= a; i++)
    {
        e[i].resize(0);
        mx[i] = 0;
        mn[i] = INT_MAX;
    }
    for (int i = 1; i < a; i++)
    {
        int p;
        cin >> p;
        e[p].push_back(i+1);
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        mx[x] = i;
        mn[x] = i;
    }
    dfs(1, 0);
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    input();
    input();
    memset(dp, 0, sizeof(dp));
    for (int i = 1;i <= n; i++)
    {
        dp[i] = dp[i-1];
        for (pair <int, int> pp: seg[i])
        {
            int v = pp.first;
            int num = pp.second;

            //cout << i << " " << v << " " << num <<  endl;
            dp[i] = max(dp[i], dp[v-1] + num);
        }
    }
    cout << dp[n] + ans;
    return 0;
}
