#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+100;
int n;
long long a[maxn], ans = 0, mx;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    ans = a[n], mx = a[n];
    for (int i = n-1; i >= 1; i--)
    {
        mx = min(mx-1, a[i]);
        if (mx < 0)
            break;
        ans += mx;
    }
    cout << ans;
    return 0;
}
