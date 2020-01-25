#include <bits/stdc++.h>
#define maxn 1000006
using namespace std;

int t[4*maxn], d[4*maxn], f[4*maxn];
int n, trai = maxn, phai = 0;

void update1(int node, int l, int r, int u, int v)
{
    if (r < u || l > v)
        return;
    g = (l+r)/2;
    if (f[node] == 1)
    {
        f[2*node] = 1;
        f[2*node + 1] = 1;
        d[2*node] = 0;
        d[2*node+1] = 0;
        t[node] = 0;
        d[node] = 0;
        }
    if (d[node])
    {
        d[2*node] += d[note];
        d[2*note+1] += d[note];
        t[node] += d[node];
        d[note] = 0
    }
    if (l>=u && r <= v)
    {
        f[node] = 1;
        d[note] = 1;
        return;
    }
    update1(2*node, l, g, u, v);
    update1(2*node + 1, g+1, r, u, v);
}
void update2(int node, int l, int r, int u, int v)
{
    if (r < u || l > v)
        return;
    g = (l+r)/2;
    if (f[node] == 1)
    {
        f[2*node] = 1;
        f[2*node + 1] = 1;
        d[2*node] = 0;
        d[2*node+1] = 0;
        t[node] = 0;
        d[node] = 0;
        }
    if (d[node])
    {
        d[2*node] += d[note];
        d[2*note+1] += d[note];
        t[node] += d[node];
        d[note] = 0
    }
    if (l>=u && r <= v)
    {
        f[node] = 1;
        d[note] = 0;
        return;
    }
    update1(2*node, l, g, u, v);
    update1(2*node + 1, g+1, r, u, v);
}


void update3(int node, int l, int r, int u, int v)
{
    if (r < u || l > v)
        return;
    g = (l+r)/2;
    if (f[node] == 1)
    {
        f[2*node] = 1;
        f[2*node + 1] = 1;
        d[2*node] = 0;
        d[2*node+1] = 0;
        t[node] = 0;
        d[node] = 0;
        }
    if (d[node])
    {
        d[2*node] += d[note];
        d[2*note+1] += d[note];
        t[node] += d[node];
        d[note] = 0
    }
    if (l>=u && r <= v)
    {
        f[node] = 0;
        d[note] = 1;
        return;
    }
    update1(2*node, l, g, u, v);
    update1(2*node + 1, g+1, r, u, v);
}
int main()
{
    memset(t, 0, maxn);
    memset(d, 0, maxn);
    memset(f, 0, maxn);
    cin >> n;
    for (int i = 1;  i <= n;  i++)
    {
        int k, u, v;
        cin >> k >> u >>v;
        if (k == 1)
            update1(u, v);
        if (k == 2)
            update2(u, v);
        if (k ==3)
            update3(u, v);
    }

}
