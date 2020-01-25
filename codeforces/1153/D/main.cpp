#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5+100, maxc = 1e9;

int n, cnt = 0;
int a[maxn], num[maxn];
vector <int> e[maxn];

void dfs(int u)
{
    if (a[u] == 1)
    {
        num[u] = maxc;
    }
    if (e[u].size() == 0)
    {
        cnt ++;
        num[u] = 1;
        return;
    }
    for (int i = 0; i < e[u].size(); i++)
    {
        int v = e[u][i];
        dfs(v);
        if (!a[u])
            num[u] += num[v];
        else
            num[u] = min(num[u], num[v]);
    }
    return ;
}

int main()
{
   // freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++)
    {
        int v;
        cin >> v;
        e[v].push_back(i);
    }
    dfs(1);
    cout << cnt-num[1]+1;
    return 0;
}
