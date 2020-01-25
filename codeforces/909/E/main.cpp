#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

deque <int> q[2];
int n, m, ans = 0;
int a[maxn], tt = 0, cnt[maxn];
vector <int> e[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[v].push_back(u);
        cnt[u] ++;
    }
    for (int i = 0; i < n; i++)
        if (cnt[i] == 0)
            q[a[i]].push_back(i);
    while (q[0].size() || q[1].size())
    {
        if (q[tt].size() == 0)
        {
            if (tt == 0)
                ans++;
            tt = !tt;
        }
        int u = q[tt].front();
        for (int i = 0; i < e[u].size(); i++)
        {
            int v = e[u][i];
            cnt[v] --;
            if (cnt[v] == 0)
                q[a[v]].push_back(v);
        }
        q[tt].pop_front();
    }
    cout << ans;
    return 0;
}
