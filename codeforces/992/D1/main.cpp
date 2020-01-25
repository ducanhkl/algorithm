#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+7;
long long a[maxn];
int pre[maxn], n, k;
long long ans = 0;

long long solve(int pos)
{
    long long res = 0;
    long long p = 1, s = 0;
    while (pos)
    {
        if (LONG_MAX/a[pos] < p)
            break;
        p *= a[pos];
        s += a[pos]*k;
        int cntone = pos-pre[pos]-1;
        if (p >= s && (p-s)%k == 0)
            res += (int)((p-s)/k <= cntone);
        pos = pre[pos];
        s += k*cntone;
    }
    return res;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    pre[0] = 0;
    for (int i = 1; i <= n; i++)
        if (a[i-1] == 1)
            pre[i] = pre[i-1];
        else
            pre[i] = i-1;
    for (int i = 1; i <= n; i++)
        ans += solve(i);
    cout << ans;
}
