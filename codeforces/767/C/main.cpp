#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;


int dd[maxn], res[4], s = 0, n, dem = 0, root;
vector <int> e[maxn];

void dfs(int u)
{
    for (int i = 0; i < e[u].size(); i++)
    {
        dfs(e[u][i]);
        dd[u] += dd[e[u][i]];
    }
    if (dd[u] == s/3 && u != root)
        res[++dem] = u, dd[u] = 0;
    if (dem == 2)
    {
        cout << res[1] << " "<< res[2];
        exit(0);
    }
    return;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, t;
        cin >> x >> t;
        dd[i] = t;
        s += t;
        if (x == 0)
            root = i;
        else
            e[x].push_back(i);
    }
    if (s%3 != 0)
        return cout << -1, 0;
    dfs(root);
    cout << -1;
    return 0;
}
