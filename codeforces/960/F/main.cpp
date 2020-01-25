#include <bits/stdc++.h>
#define maxn 100006
#define maxw 100006

using namespace std;

map <int, int> tree[maxn];
int n, m, ans = 0;

void update (int u, int w, int x)
{
    for (;w < maxw; w += (w&(-w)))
        tree[u][w] = max(tree[u][w], x);
    return;
}

int get(int u, int w)
{
    int res = 0;
    for (; w > 0; w -= (w&(-w)))
        res = max(res, tree[u][w]);
    return res;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            int t = get(u, w) + 1;
            update(v, w+1, t);
        }
    for (int i = 1; i <= n; i++)
        ans = max(ans, get(i, maxw));
    cout << ans;
    return 0;
}
