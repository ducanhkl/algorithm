#include <bits/stdc++.h>

using namespace std;


const int maxn = 3000;

struct point
{
    int x, y;
} a[maxn];

int n;
long long ans[maxn], c[maxn], k[maxn], mincost = 0;
priority_queue < pair <long long, int> > q;
int par[maxn], done[maxn];
vector <int> ver;
vector <pair <int, int> > eg;

long long dis(int u, int v)
{
    return (k[u] + k[v])*(abs(a[u].x - a[v].x) + abs (a[u].y - a[v].y));
}


void solve()
{
    for (int i = 1; i <= n; i++)
    {
        ans[i] = c[i];
        q.push({-ans[i], i});
        par[i] = i;
    }
    while (q.size())
    {
        int u = q.top().second;
        long long w = -q.top().first;
        q.pop();
        if (w > ans[u])
            continue;
        done[u] = 1;
        for (int v = 1; v <= n; v++)
        {
            long long l = dis(v, u);
            if (done[v])
                continue;
            if (l  < ans[v] )
            {
                ans[v] = l;
                par[v] = u;
                q.push({-ans[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (par[i] == i)
        {
            mincost += c[i];
            ver.push_back(i);
        } else
        {
            mincost += dis(i, par[i]);
            eg.push_back({i, par[i]});
        }
    }
    cout << mincost << endl;
    cout << ver.size() << endl;
    for (auto u : ver)
        cout << u << " ";
    cout << endl;
    cout << eg.size() << endl;
    for (auto u : eg)
        cout << u.first << " " << u.second << endl;
    return ;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
    }
    for (int i = 1; i<= n; i++)
        cin >> c[i];
    for (int i =1 ; i <= n; i++)
        cin >> k[i];
    solve();
    return 0;
}
