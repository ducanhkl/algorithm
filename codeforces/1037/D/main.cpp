#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int n, now, t;
int a[maxn], mark[maxn], dd[maxn], tt[maxn];
vector <int> e[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(dd, 0, sizeof(dd));
    memset(mark, 0, sizeof(mark));
    memset(tt, 0, sizeof(tt));
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
        cin >> a[i];
    dd[1] = 1, now = t = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dd[a[i]] == 0 || mark[a[i]] == 1 || tt[a[i]] < now)
            return cout << "No", 0;
        dd[a[i]] = 1, mark[a[i]] = 1, now = tt[a[i]];
        t++;
        for (int j = 0; j < e[a[i]].size(); j++)
        {
            int v = e[a[i]][j];
            dd[v] = 1;
            tt[v] = t;
        }
    }
    cout << "Yes";
    return 0;
}
