#include "bits/stdc++.h"

using namespace std;

const int maxn = 2e5+100;

int n, m, ans = 0;
int root[maxn];

int getroot(int u)
{
    if (root[u] == 0)
        return u;
    return  root[u] = getroot(root[u]);
}

void join(int u, int v)
{
    int paru = getroot(u);
    int parv = getroot(v);
    if (paru == parv)
        return ;
    if (paru > parv)
    {
        swap(paru, parv);
    }
    root[paru] = parv;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        join(u, v);
    }
    int maxv = 0;
    for (int i = 1; i <= n; i++)
    {
        if (maxv <= getroot(i))
        {
            maxv = getroot(i);
        } else
        {
            ans ++;
            join(i, maxv);
        }
    }
    cout << ans;
}