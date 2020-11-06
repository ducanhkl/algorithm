#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e3+100;

int n, m, n1, n2, n3;
int vis[maxn], cnt[maxn][3], res[maxn], h[maxn];
bitset <maxn> dd[maxn];
vector <int> e[maxn];
int tp = 0;

void dfs(int u)
{
    vis[u] = tp;
    cnt[tp][h[u]] ++;
    for (int v : e[u])
    {
        if (vis[v])
        {
            if (h[u] == h[v])
            {
                cout << "NO";
                exit(0);
            }
        } else {
            h[v] = h[u]^1;
            dfs(v);
        }
    }
    return ;
}

int main()
{
    //freopen("inp.txt", "r" , stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    cin >> n1 >> n2 >> n3;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >>u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 1; i<= n; i++)
    {
        if (vis[i])
            continue;
        tp++;
        dfs(i);
    }
    dd[0][0] = 1;
    for (int i = 1; i <= tp;  i++)
    {
        dd[i] = (dd[i-1] << cnt[i][0]) | (dd[i-1] << cnt[i][1]);
    }
    if (dd[tp][n2] == 0)
    {
        cout << "NO";
        return 0;
    }
    int cur = n2;
    cout << "YES" << endl;
    for (int i = tp; i >= 1; i--)
    {
        if (cur >= cnt[i][0] && dd[i-1][cur-cnt[i][0]] == 1)
            cur -= cnt[i][0];
        else
        {
            cur -= cnt[i][1];
            res[i] = 1;
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        if (h[i] == res[vis[i]])
            cout << 2;
        else
            if (n1 > 0)
        {
            cout << 1;
            n1--;
        } else
        {
            cout << 3;
        }
    }
    return 0;
}
