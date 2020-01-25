#include <bits/stdc++.h>

using namespace std;

pair <int, int> a[2300];
int n, dd[2300], ans = 0, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first, a[i].second = i;
    sort(a+1, a+n+1);
    for (int i = 1; i <= k; i++)
        dd[i] = a[n-i+1].second, ans += a[n-i+1].first;
    sort(dd+1, dd+k+1);
    cout << ans << endl;
    dd[0] = 0;
    for (int i = 1; i < k; i++)
        cout << dd[i] - dd[i-1]<< " ";
    cout << n - dd[k-1];
    return 0;
}
