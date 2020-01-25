#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define maxn 10006

using namespace std;

ll dd[maxn], ans = 0;
int n, m;

void bfs(int x)
{
    queue <int> t;
    for (int i = 1; i <= n; i++)
        dd[i] = -1;
    dd[1] = 0;
    t.push(1);
    while(!t.empty())
    {
        int u = t.front();
        t.pop();
        for (int i = 0; (u - (1 << i)) > 0; i++)
            if (dd[u-(1<<i)] == -1)
            {
                dd[u-(1<<i)] = dd[u] + 1;
                t.push(u-(1<<i));
            }
        for (int i = 0; (u + (1<<i)) <= n; i++)
            if (dd[u+(1<<i)] == -1)
        {
            dd[u+(1<<i)] = dd[u] + 1;
            t.push(u+(1<<i));
        }
    }
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    bfs(1);
    for (int i= 2; i <= n; i++)
        ans += dd[i] * 3LL * n * n;
    cout << ans << endl;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        cout << dd[a] + dd[b] + dd[c] << endl;
    }
    return 0;
}
