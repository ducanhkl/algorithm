#include <bits/stdc++.h>

using namespace std;

const int maxn = 30010;

int root[maxn], active[maxn], visited[maxn], cnt[maxn];
vector <int> e[maxn];
int n, m;
stack <int> st;

int get_root(int u)
{
    if (root[u] == 0)
        return u;
    return (root[u] = get_root(root[u]));
}

void dfs(int u)
{
    visited[u] = 1;
    st.push(u);
    for (auto v : e[u])
    {
        if (visited[v] == 0)
            continue;
        v = get_root(active[v]);
        while (st.top() != v)
        {
            int r = get_root(st.top());
            root[r] = v;
            st.pop();
        }
    }
    for (auto v: e[u])
    {
        if (visited[v])
            continue;
        active[u] = v;
        dfs(v);
    }
    if (st.top() == u)
    {
        st.pop();
    }
    return ;
}

void solve()
{
    memset(root, 0, sizeof(root));
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cnt[get_root(i)] ++;
    }
    return;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >>u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    solve();
    cout << 1+*max_element(cnt+1, cnt+n+1);
    return 0;
}
