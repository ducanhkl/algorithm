#include <bits/stdc++.h>

using namespace std;


typedef pair <int, int> ii;
typedef pair <long long, ii > pii;
const int maxn = 1e4+100;

int n, m, k, s1, s2, f;
int d[maxn][3];
int t[maxn], l[maxn], r[maxn];
vector <int> e[maxn];

void solve()
{
    priority_queue < pii > q;
    for (int i = 1; i <= n; i++)
        d[i][0] = d[i][1] = INT_MAX;
    d[s1][0] = 0;
    d[s2][1] = 0;
    q.push({0, {s1, 0}});
    q.push({0, {s2, 1}  });
    while (q.size())
    {
        int u = q.top().second.first;
        int w = q.top().second.second;
        long long L = -q.top().first;
        q.pop();
        if (d[u][w] < L)
            continue;
        for (auto i : e[u])
        {
            if (i > m && w == 1 && d[u][1] < d[u][0])
                l[i] = r[i];
            int v = t[i];
            if (L+l[i] < d[v][w])
            {
                d[v][w] = L+l[i];
                q.push({-d[v][w], {v, w}});
            }
        }
    }
    return ;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    cin >> s1 >> s2 >> f;
    for (int i = 1; i <= m; i++)
    {
        int v;
        cin >> v >> t[i] >> l[i];
        e[v].push_back(i);
    }
    for (int i = m+1;  i <= m+k; i++)
    {
        int v;
        cin >> v >> t[i] >> l[i] >> r[i];
        e[v].push_back(i);
    }
    solve();
    if (d[f][0] > d[f][1])
    {
        cout << "LOSE" << endl;
        return 0;
    }
    if (d[f][0] == d[f][1])
    {
        cout << "DRAW" << endl;
    }
    if (d[f][0] < d[f][1])
    {
        cout << "WIN" << endl;
    }
    for (int i = m+1; i <= m+k; i++)
        cout << l[i] << " ";
    return 0;
}
