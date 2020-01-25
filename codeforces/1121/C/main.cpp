#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;
int n, k;
int a[maxn], ma[maxn], mark[maxn], now[maxn], ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    memset(ma, 0, sizeof(ma));
    int f = 0, s = 0;
    while (f < n)
    {
        for (int i = 1; i <= k; i++)
        {
            if (!ma[i] && s < n)
                ma[i] = ++s, now[i] = 0;
            now[i] ++;
            if (!mark[ma[i]] && ma[i])
                if (now[i] == (int)(100.0*f/n+0.5))
                    ans++, mark[ma[i]] = 1;
        }
        for (int i = 1; i <= k; i++)
            if (now[i] == a[ma[i]])
                f++, ma[i] = 0;
    }
    cout << ans;
    return 0;
}
