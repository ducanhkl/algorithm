#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n, k;
int a[maxn];
long long ans = 1LL<<62, res = 0;
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1;  i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    for (int i = 2; i <= k; i++)
        res += a[i] - a[i-1];
    for (int i = k; i <= n; i++)
    {
        ans = min(min(ans, res + abs(a[i])), res  + abs(a[i-k+1]));
        res -= a[i-k+2] - a[i-k+1];
        res += a[i+1] - a[i];
    }
    cout << ans;
    return 0;
}
