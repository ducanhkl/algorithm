#include <bits/stdc++.h>
#define maxn 400

using namespace std;


struct edge
{
    long long l, w;
    int v;
    edge (int _v,int _l,int _w)
    {
        v = _v;
        l = _l;
        w = _w;
    }
};

int n, k, r;
vector <edge> e[maxn];
long long dd[maxn];

bool operator > (edge x, edge y)
{
    return x.w > y.w;
}
void ijk()
{
    for (int i = 1; i <= n; i++)
        dd[i] = INT_MAX;
    dd[1] = 0;
    priority_queue < edge, vector <edge>, greater <edge> > q;
    q.push(edge(1, 0, 0));
    while (q.size())
    {
        edge u = q.top();
        q.pop();
        if (dd[u.v] < u.l)
            continue;
        dd[u.v] = u.l;
        for (int i = 0; i < e[u.v].size(); i++)
        {
            int v = e[u.v][i].v;
            long long l = e[u.v][i].l+ u.l;
            long long w = e[u.v][i].w + u.w;
            if (w > k)
                continue;
            q.push(edge(v, l, w));
        }
    }
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        memset(e, 0, sizeof(e));
        cin >> k >> n >> r;
        for (int i = 1; i <= r; i++)
        {
            long long u, v, l, w;
            cin >> u >> v >> l >> w;
            e[u].push_back(edge(v, l, w));
        }
        ijk();
        if (dd[n] >= INT_MAX)
            cout << -1;
        else cout <<dd[n];
        cout << endl;
    }
    return 0;
}
