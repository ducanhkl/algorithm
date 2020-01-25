#include <bits/stdc++.h>
#define maxn 200006

using namespace std;

int n;
long long a[maxn], ans = LONG_LONG_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= 2*n; i++) cin >> a[i];
    sort(a+1, a+2*n+1);
    ans = min(ans, (a[2*n]-a[n+1])*(a[n] - a[1]));
    for (int i = 2; i <= n; i++)
        ans = min(ans, (a[i+n-1] - a[i])*(a[2*n] - a[1]));
    cout << ans;
    return 0;
}
