#include <bits/stdc++.h>
#define maxn 300005

using namespace std;

int n, ufr[maxn], root = 0, tr;
vector <int> e[maxn];

int dfs(int u)
{
    set<int> s;
    ufr[u] = 1;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (ufr[v])
            continue;
        int res = dfs(v);
        if (res == -1)
            return -1;
        s.insert(res+1);
    }
    if (s.size() == 0)
        return 0;
    if (s.size() > 2)
        return -1;
    if (s.size() == 2 && u == tr)
        return *s.begin() + *s.rbegin();
    if (s.size() == 1)
        return *s.begin();
    root = u;
    return -1;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    memset(ufr, 0, sizeof(ufr)), tr = 1;
    int ans = dfs(1);
    memset(ufr, 0, sizeof(ufr)), tr = root;
    if (ans == -1 && root > 0)
        ans = dfs(root);
    if (ans == -1)
        return cout << -1, 0;
    while (ans%2 == 0)
        ans /= 2;
    cout << ans;
    return 0;
}
