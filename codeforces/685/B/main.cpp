#include <bits/stdc++.h>

using namespace std;

int n, tt;
int ans[300005], cnt[300005];
vector <int> e[300005];
stack<int> q;

int dfs1(int u)
{
    cnt[u] = 1;
    for (int i = 0; i < e[u].size(); i++)
        cnt[u] += dfs1(e[u][i]);
    return cnt[u];
}

int dfs2(int u)
{
    q.push(u);
    for (int i = 0; i < e[u].size(); i++)
        dfs2(e[u][i]);
    while (q.size() && 2*cnt[u] >= cnt[q.top()])
    {
        ans[q.top()] = u;
        q.pop();
    }
    return 0;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(cnt, 0, sizeof(cnt));
    ios_base::sync_with_stdio(false);
    cin >> n >> tt;
    for (int i = 2; i <= n; i++)
    {
        int x;
        cin >> x;
        e[x].push_back(i);
    }
    dfs1(1);
    dfs2(1);
    for (int i = 1; i <= tt; i++)
    {
        int x;
        cin >> x;
        cout << ans[x] << " ";
    }
    return 0;
}
