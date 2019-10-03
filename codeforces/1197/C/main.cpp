#include <bits/stdc++.h>

using namespace std;

const int maxn = 3e5+100;
int n, k;
long long a[maxn], b[maxn], ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
        b[i] = a[i] - a[i+1];
    ans = a[n] - a[1];
    sort(b+1, b+n);
    for (int i = 1; i < k; i++)
        ans += b[i];
    cout << ans;
    return 0;
}
