#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxn 3400
#define maxnum 123456789

using namespace std;

vector <int> edge[maxn];
int a[maxn][maxn];
int kq[maxn];
int m, n;

void bfs(int r)
{
    queue <int> q;
    q.push(r);
    while(!q.empty())
    {
        int u = q.front(); q.pop();
        //cout << sizeof(edge[u]);
        for (int i = 0; i < edge[u].size(); i++)
            {
                int v = edge[u][i];
                if (v != r && !a[r][v])
                {
                    a[r][v] = a[r][u] + 1;
                    q.push(v);
                }
            }
    }
}
int main()
{
    freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    memset(a, 0, sizeof(a));
    for (int i = 1; i <= n; i++)
            bfs(i);
    memset(kq, 0, sizeof(kq));
    for (int i = 1; i <= n; i++)
        for (int j =  i + 1; j <= n; j++)
        if (a[i][j])
    {
        int k = log2(a[i][j]);
        k += (1LL << k) != a[i][j];
        kq[k] ++;
    }
    for (int i = 1; i <= maxn; i++)
    {
        cout << kq[i] << " ";
        if (kq[i] == 0)
            return 0;
    }
	return 0;
}
