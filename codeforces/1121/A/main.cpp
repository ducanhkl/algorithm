#include <bits/stdc++.h>

using namespace std;

const int maxn = 200;
int n, m, k, res = 0;
int ans[maxn], p[maxn], s[maxn];

int main()
{
    memset(ans, 0, sizeof(ans));
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
        ans[s[i]] = max(ans[s[i]], p[i]);
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        if (ans[s[x]] > p[x])
            res ++;
    }
    cout << res;
    return 0;
}
