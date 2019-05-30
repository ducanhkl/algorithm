#include <bits/stdc++.h>
#define maxn 500

using namespace std;


int t, n, m, c;
unsigned long long dd[maxn];
vector <pair<int, long long> > e[maxn];

long long calc(long long w, long long c, long long l)
{
    if (w - (c - l) <= 0)
        return l;
    if (c <= 2*l)
        return 91234567898;
    long long t = (w  + l - c)/(c-2*l);
    if ((w + l - c)% (c-2*l) > 0)
        t++;
    return (2*t+1)*l;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        memset(e, 0, sizeof(e));
        cin >> n >> m >> c;
        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            e[u].push_back({v, w});
            e[v].push_back({u, w});
        }
        for (int i = 1; i <= n; i++)
            dd[i] = 91234567898;
        dd[n] = 0;
        priority_queue <pair <long long, int> >q;
        q.push({0, n});
        while (q.size())
        {
            pair <long long, int> t = q.top();
            q.pop();
            if (dd[t.second] < -t.first)
                continue;
            int u = t.second;
            dd[u] = -t.first;
            for (int i = 0; i < e[u].size(); i++)
            {
                int v = e[u][i].first;
                long long l = e[u][i].second;
                long long w = dd[u] + calc(dd[u], c, l);
                if (w < dd[v])
                {
                    dd[v] = w;
                    q.push({-w, v});
                }
            }
        }
        cout << dd[1] << endl;
    }
    return 0;
}
