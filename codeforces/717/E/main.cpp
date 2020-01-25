#include <bits/stdc++.h>
#define maxn 200006

using namespace std;

int ufr[maxn], a[maxn];
int n;
vector <int> e[maxn];

void w(int u)
{
    a[u] *= -1;
    cout << u << " ";
    //for (int i = 1; i <= n; i++)
     //   cout << a[i] << " ";
    //cout << endl;
}

void dfs(int u)
{
    ufr[u] = 1;
    w(u);
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        if (ufr[v] == 0)
        {
            dfs(v);
            w(u);
            if (a[v] < 0)
                w(v), w(u);
        }
    }
    return ;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    memset(ufr, 0, sizeof(ufr));
    dfs(1);
    if (a[1] > 0)
        w(e[1][0]), w(1), w(e[1][0]);
    return 0;
}
