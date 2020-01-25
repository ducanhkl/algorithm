#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    init();
    q.push(zr);
    while (q.size())
    {
        vector <int> now = q.front();
        q.pop();
        vector <ii> w[10];
        for (auto u: now)
        {
            for (auto [to, co]: e[u])
            {
                if (!ufr[to])
                    w[co].push_back({to, u});
            }
        }
        for (int i = 0; i <= 10; i++)
        {
            vector <int> t ;
            for (int j = 0; j < w[i].size(); j++)
            {

            }
        }
    }
    return 0;
}
