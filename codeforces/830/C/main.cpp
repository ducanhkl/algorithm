#include <bits/stdc++.h>

using namespace std;

const long long maxn = 200;
long long n, k, ans  = 0;
long long a[maxn];

bool check(long long val)
{
    long long res = 0;
    for (int i = 1; i <= n; i++)
    {
        res += (a[i]/val) + (a[i]%val != 0);
    }
    return res*val <= k;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        k += a[i];
    }
    for (long long i = 1; i*i <= k+1; i++)
    {
        if (check(k/i))
            ans = max(ans, k/i);
        if (check(i))
            ans = max(ans, i);
    }
    cout << ans;
    return 0;
}
