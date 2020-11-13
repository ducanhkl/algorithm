#include <bits/stdc++.h>

using namespace std;


const int maxn = 1e6+100;


long long seg_tree[5*maxn], f[5*maxn];
long long a[maxn], b[maxn], ans[maxn];
map <long long, int> mm;
vector <pair<int, int> > e[maxn];
int n, m, q;

void push_up(int node)
{
    seg_tree[node] = min(seg_tree[2*node], seg_tree[2*node+1]);
    return ;
}

void push_down(int node_cha, int node_con)
{
    seg_tree[node_con] += f[node_cha];
    f[node_con] += f[node_cha];
    return ;
}

void update(int node, int l, int r, int u, int v, int  val)
{
    if (l > v || r < u)
    {
        return ;
    }

    if (u <= l && r <= v)
    {
        seg_tree[node] += val;
        f[node] += val;
        return ;
    }
    if (f[node])
    {
        push_down(node, 2*node);
        push_down(node, 2*node+1);
        f[node] = 0;
    }
    int mid = (l+r)>>1;
    update(2*node, l, mid, u, v, val);
    update(2*node+1, mid+1, r, u, v, val);
    push_up(node);
}

int main()
{
    // freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    for (int i = 1; i < n; i++)
    {
        cin >> a[i] >> b[i];
        update(1, 1, n, i+1, i+1, b[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto p : e[i])
        {
            int v = p.first;
            long long w = p.second;
            update(1, 1, n, 1, v, w);
        }
        // cout << a[i] << " " << seg_tree[1] << endl;
        ans[i] = seg_tree[1] + a[i];
        mm[ans[i]] ++;
    }
    cout << mm.begin()->first << endl;
    for (int i = 1; i <= q; i++)
    {
        int u;
        long long w;
        cin >> u >> w;
        auto it = mm.find(ans[u]);
        --(it->second);
        int cnt = it->second;
        if (cnt == 0)
        {
            mm.erase(it);
        }
        ans[u] -= a[u];
        a[u] = w;
        ans[u] += a[u];
        mm[ans[u]] ++;
        cout << mm.begin()->first << endl;
    }
    return 0;
}
