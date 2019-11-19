#include <bits/stdc++.h>

using  namespace std;

const int maxn = 3e5+100;
int n, m;
int a[maxn], b[maxn], st[maxn], en[maxn];

void solve()
{
    for (int i = 1; i <= n; i++) {
        if (st[a[i]] == 0)
            st[a[i]] = i;
        en[a[i]] = i;
    }
    int res = 1, last = 0, cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        if (last < st[i])
            cnt ++, res = max(res, cnt);
        else
            cnt = 1;
        last = en[i];
    }
    cout << m - res << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    int test;
    cin >> test;
    while (test--)
    {
        for (int i = 1; i <= n; i++)
            st[i] = en[i] = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i], b[i] = a[i];
        sort(b+1, b+n+1);
        m = unique(b+1, b+n+1) - b - 1;
        for (int i = 1; i <= n; i++)
            a[i] = lower_bound(b+1, b+m+1, a[i]) - b;
        solve();
    }
    return 0;
}