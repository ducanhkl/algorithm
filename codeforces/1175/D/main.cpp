#include <bits/stdc++.h>

using namespace std;

const int maxn = 3*1e5;
long long a[maxn];
int n, k;
long long ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        a[i] += a[i-1];
    sort(a+1, a+n);
    for (int i = 1; i < k; i++)
        ans -= a[i];
    ans += a[n]*k;
    cout << ans;
    return 0;
}
