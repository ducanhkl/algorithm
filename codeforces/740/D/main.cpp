#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int u, w;
        cin >> u >> w;
        e[u].push_back({i+1, w});
        e[i+1].push_back({u, w});
    }

    return 0;
}
