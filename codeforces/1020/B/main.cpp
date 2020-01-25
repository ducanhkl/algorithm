#include <bits/stdc++.h>
#define maxn 1200

using namespace std;

int n;
int p[maxn], dd[maxn];

int dfs(int u)
{
    dd[u]++;
    if (dd[u] == 2)
        return u;
    return dfs(p[u]);
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++)
        memset(dd, 0, sizeof(dd)), cout << dfs(i) << " ";
    return 0;
}
