#include <bits/stdc++.h>
#define maxn 12345

using namespace std;


vector <pair <int, int> > a[maxn];
int n, m, x, y;
int dd[maxn];

void nhap()
{
    cin >> n >> m >> x >> y;
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v;
        cin >> w;
        a[u].push_back(make_pair(v, w));
        a[v].push_back(make_pair(u, w));
    }
}

void ijk(int s,int d[])
{
    memset(d, 60, maxn);
    d[s] = 0;
    priority_queue <pair<int, int> > p;
    p.push(make_pair(0,s));
    while(!p.empty())
    {
        int u = p.top().second;
        int l = - p.top().first;
        p.pop();
        if(l > d[u]) continue;
        for(int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i].first;
            int w = a[u][i].second;
            if(d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                p.push(make_pair(-d[v], v));
            }
        }
    }
}
int main()
{
    freopen("inp.txt", "r", stdin);
    nhap();
    ijk(x, dd);
    cout << dd[y];
    return 0;
}
