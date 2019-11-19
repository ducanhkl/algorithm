#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int root[maxn], x[maxn], y[maxn];
int n, k, ans = 0;

int getroot (int u)
{
    if (root[u] == 0)
        return u;
    return root[u] = getroot(root[u]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    memset(root, 0, sizeof(root));
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> x[i] >> y[i];
        int u = getroot(x[i]);
        int v = getroot(y[i]);
        if (u != v)
        {
            root[u] = v;
        } else
        ans ++;
    }
    cout << ans;
    return 0;
}
