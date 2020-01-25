#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;

int n;
long long x[maxn], y[maxn], s[maxn], top = 0, h[maxn], p[maxn][25];

int ccw(int i, int j, int k)
{
    /*long long a1 = x[j] - x[i];
    long long b1 = y[j] - y[i];
    long long a2 = x[k] - x[j];
    long long b2 = y[k] - y[j];
    return a1*b2 - b1*a2;*/
    return (x[j]-x[k])*(y[i]-y[k])-(x[i]-x[k])*(y[j]-y[k])<0;
}

int getpar(int u, int dis)
{
    for (int i = 20; i >= 0; i--)
        if ((dis>>i)&1)
            u = p[u][i];
    return u;
}

int lca(int u, int v)
{
    if (h[u] > h[v])
        swap(u, v);
    int dis = h[v] - h[u];
    v = getpar(v, dis);
    if (u == v)
        return u;
    for (int i = 20; i >= 0; i--)
        if (p[u][i] != p[v][i])
    {
        u = p[u][i];
        v = p[v][i];
    }
    return p[u][0];
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    memset(h, 0, sizeof(h));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    s[++top] = n;
    p[n][0] = n;
    for (int i = n-1; i >= 1; i--)
    {
        while (top > 1 && ccw(i, s[top], s[top-1]))
            top --;
        p[i][0] = s[top];
        h[i] = h[s[top]]+1;
        s[++top] = i;
    }
    for (int i = 1; i <= 20; i++)
    {
        for (int u = 1; u <= n; u++)
            p[u][i] = p[p[u][i-1]][i-1];
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << " ";
    }
    return 0;
}
