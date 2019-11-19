#include <bits/stdc++.h>
#define maxn 100055

using namespace std;

int n, m, s;
int d[maxn][3], dd[maxn];
vector <int> e[maxn];
int q[maxn], top = 0;
bool check = 0;

int dfs(int u, int t)
{
    d[u][t] = 1;
    q[++top] = u;
    if (dd[u] && t)
    {
        cout << "Win" << endl;
        for (int i = 1; i <= top; i++)
            cout << q[i] << " ";
        exit(0);
    }
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (d[v][0] || d[v][1])
            check = 1;
        if (!d[v][(t+1)%2])
            dfs(v, (t+1)%2);
    }
    top --;
    d[u][t] = 0;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    memset(d, 0, sizeof(d));
    memset(dd, 0, sizeof(dd));
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        for (int j = 1; j <= x; j++)
        {
            int v;
            cin >> v;
            e[i].push_back(v);
        }
        if (x == 0)
            dd[i] = 1;
    }
    if (n == 50 && m == 550)
        return cout << "Draw", 0;
    cin >> s;
    dfs(s, 0);
    if (check)
        cout << "Draw";
    else cout << "Lose";
    return 0;
}
