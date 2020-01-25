#include <bits/stdc++.h>
#define maxn 10005

using namespace std;

int dd[maxn], k, n;
vector <int> e[maxn];
int ans = 0;

void dfs(int u)
{
    for (int i = 0; i < e[u].size(); i++)
    {
        dfs(e[u][i]);
        dd[u] += dd[e[u][i]];
    }
    if (dd[u] >= k)
        dd[u] = 0, ans ++;
}
int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> k >> n;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        e[x].push_back(i);
        dd[i] = 1;
    }
    dd[1] = 1;
    dfs(1);
    cout << ans;
    return 0;
}
