#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        in[a[i]] = 1;
    }
    for (int i = 1; i <= n; i++)
        if (in[a[i]] == 0)
            kq.push_back({i, dfs(i)});

    return 0;
}
