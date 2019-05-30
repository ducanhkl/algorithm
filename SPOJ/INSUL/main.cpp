#include <bits/stdc++.h>

using namespace std;

int n, a[100001];
int ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i], ans += a[i];
    sort(a, a+n);
    for (int i = 0; i < n/2; i++)
        ans += a[n-i-1] - a[i];
    if (n%2)
    {
        ans -= a[n/2+1] - a[n/2-1];
        ans += max(a[n/2+1] - a[n/2] + a[n/2] - a[n/2-1], a[n/2+1] - a[n/2-1]);
    }
    cout << ans;
    return 0;
}
