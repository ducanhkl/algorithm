#include <bits/stdc++.h>

using namespace std;

const int maxn = 5000;

int n;

int dd[maxn], e[maxn][maxn];
vector<int> a[maxn];

void dfs(int u, int cnt)
{
    dd[u] = cnt;
    a[cnt].push_back(u);
    for (int i = 1; i <= n; i++)
    {
        if (e[u][i])
        {
            if (!dd[i])
            {
                dd[i] = cnt;
                dfs(i, cnt);
            }
        }
    }
}

void solve()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dd[i] == 0)
        {
            cnt++;
            a[cnt].clear();
            dfs(i, cnt);
        }
    }
    if (cnt == 1)
    {
        cout << 0 << endl;
        return ;
    }
    int u_min = 1;
    for (int i = 1; i <= cnt; i++)
    {
        if (a[i].size() < a[u_min].size())
        {
            u_min = i;
        }
        if (a[i].size() == 1)
        {
            cout << 1 << endl << a[i][0] << endl;
            return;
        }
        pair<int,int> min_pair = { INT_MAX, -1};
        for (auto u1 : a[i])
        {
            int c = 0;
            for (auto u2 : a[i])
            {
                c += e[u1][u2];
            }
            min_pair = min(min_pair, {c, u1});
        }
        if (min_pair.first < a[i].size() - 1)
        {
            cout << 1 << endl << min_pair.second << endl;
            return;
        }
    }
    if (cnt >= 3)
    {
        cout << 2 << endl << a[1][0] << " " << a[2][0] << endl;
        return;
    }
    cout << a[u_min].size() << endl;
    for (auto u : a[u_min])
    {
        cout << u << " ";
    }
    cout << endl;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while(test--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            dd[i] = 0;
            for (int j = 1; j <= n; j++)
            {
                char x;
                cin >> x;
                x -= '0';
                e[i][j] = x;
            }
        }
        solve();
    }
    return 0;
}
