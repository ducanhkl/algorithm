#include <bits/stdc++.h>

using namespace std;

const int maxn = 400;
typedef pair<int, int> pii;

int n;
int w[maxn], p[maxn][maxn], dd[maxn];

void solve() {
    priority_queue<pii> q;
    for (int i = 1; i <= n; i++)
    {
        q.push({-w[i], i});
    }
    while (q.size())
    {
        int u, l;
        tie(l, u) = q.top();
        l = -l;
        q.pop();
        if (dd[u])
            continue;
        dd[u] = 1;
        if (l > w[u])
        {
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            if (u == i)
                continue;
            if (dd[i])
                continue;
            if (p[u][i] < w[i])
            {
                w[i] = p[u][i] ;
                q.push({-w[i], i});
            }
        }
    }
}

int main()
{
    // freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }
    for (int i = 1;  i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> p[i][j];
        }
    }
    solve();
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += w[i];
    }
    cout << ans;
    return 0;
}
