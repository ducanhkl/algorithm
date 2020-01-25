#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define maxn 100005

using namespace std;

int n, dem = 0;
int color[maxn], root[maxn], dd[maxn];

vector <int> e[maxn];

void dfs(int u)
{
    dd[u] = true;
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (dd[v] == 0)
        {
            root[v] = u;
            dfs(v);
        }
    }
}
int main()
{
    memset(dd, 0, sizeof(dd));
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for(int i = 1; i < n; i++)
        {
            int x;
            cin >> x;
            e[i+1].push_back(x);
            e[x].push_back(i+1);
        }
    for (int i = 1; i <= n; i++)
        cin >> color[i];
    dfs(1);
    for (int i = 2; i <= n; i++)
        if (color[i] != color[root[i]])
            dem ++;
    cout << dem + 1;
    return 0;
}
