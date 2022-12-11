#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+100;
const long long mod = 1e9+7;

deque<int> q;
vector<int> dp[maxn];
int n, m;
int l[maxn], r[maxn], a[maxn];

void dfs(int u)
{
    if (l[u])
    {
        dfs(l[u]);
    }
    if (r[u])
    {
        dfs(r[u]);
    }
    for (int i = 1; i <= m; i++)
    {
        long long res1 = 1, res2 = 1;
        if(l[u])
        {
            res1 = dp[l[u]][i-1];
        }
        if (r[u])
        {
            res2 = dp[r[u]][i];
        }
        dp[u][i] = (res1 * res2) % mod;
        dp[u][i] = (dp[u][i]+ dp[u][i-1]) % mod;
    }
}

void prepare()
{
    q.resize(0);
    for (int i = 0; i <= n; i++)
    {
        l[i] = r[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        while(q.size() && a[q.back()] < a[i])
        {
            l[i] = q.back();
            q.pop_back();
        }
        if (q.size())
        {
            r[q.back()] = i;
        }
        q.push_back(i);
    }
}

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        dp[i].resize(m+1);
        fill(dp[i].begin(), dp[i].end(), 0LL);
    }
    int root = q.front();
    dfs(root);
    cout << dp[root][m] << endl;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        prepare();
        solve();
    }
    return 0;
}
