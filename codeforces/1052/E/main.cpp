#include <bits/stdc++.h>

using namespace std;

const long long maxn = 1e3+100;
int n;
int b[maxn], c[maxn], g[maxn], cnt = 0, mark[maxn];
map <int, vector <int> > e;
vector <int> ans;

void dfs(int u)
{
    for (int i = e[u].size()-1; i >= 0; i = e[u].size()-1)
    {
        int pos = e[u][i];
        int v = b[e[u][i]]+c[e[u][i]]-u;
        e[u].pop_back();
        if (mark[pos])
            continue;
        mark[pos] = 1;
        dfs(v);
    }
    ans.push_back(u);
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    memset(mark, 0, sizeof(mark));
    cin >> n;
    for (int i = 1; i < n; i++)
        cin >> b[i];
    for (int i = 1; i < n; i++)
    {
        cin >> c[i];
        if (b[i] > c[i])
            return cout << -1, 0;
        e[b[i]].push_back(i);
        e[c[i]].push_back(i);
    }
    for (auto v : e)
    {
        vector <int> vec = v.second;
        if (vec.size() % 2)
        {
            g[++cnt] = v.first;
        }
    }
    if (cnt > 2)
        return cout << -1, 0;
    if (cnt == 2)
        dfs(g[1]);
    else
    {
        dfs(b[1]);
    }
    if (ans.size() != n)
        return cout << -1, 0;
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}
