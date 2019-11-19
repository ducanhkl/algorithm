#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define maxn 1000006

using namespace std;

pii a[maxn];
vector <int> e[maxn];
ll ans = 0;
int n, dd[maxn], m, t;

int dfs(int x)
{
    for (int i = 0; i < e[x].size(); i++)
        if (dd[e[x][i]] == 0 && e[x][i] != t)
        {
            dd[e[x][i]] = 1;
            dfs(e[x][i]);
        }
    return 0;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(dd, 0, sizeof(dd));
    ios_base::sync_with_stdio(false), cin.tie(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first, a[i].second = i;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++)
        if (dd[a[i].second] == 0)
            t = a[i].second, dfs(a[i].second), ans += a[i].first;
    cout << ans;
    return 0;
}
