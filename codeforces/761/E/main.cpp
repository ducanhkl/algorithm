#include <bits/stdc++.h>
#define maxn 100

using namespace std;

long long dx[] = {-1, 1, 0, 0};
long long dy[] = {0, 0, -1, 1};
pair <long long, long long> co[maxn];
vector <int> e[maxn];
int d[maxn], n;


void dfs(int u, long long l)
{
    int f = 0;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (d[v] != -1 || v == 1)
            continue;
        if (f == (d[u]^1) && u != 1)
            f++;
        co[v].first = co[u].first + l*dx[f];
        co[v].second = co[u].second + l*dy[f];
        d[v] = f;
        dfs(v, l>>1);
        f++;
    }
    return ;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
        if (e[i].size() > 4)
            return cout << "NO", 0;
    for (int i = 1; i <= n; i++)
        d[i] = -1;
    dfs(1, 1<<30);
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++)
        cout << co[i].first << " " << co[i].second << endl;
    return 0;
}
