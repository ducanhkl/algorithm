#include <bits/stdc++.h>

using namespace std;


const int maxn = 2000;
int a[maxn];
int n, k;

void solve()
{
    cin >> n >>  k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort (a+1, a+n+1);
    int ans = 0;
    for (int i = 2; i <= n; i++)
    {
        ans += (k-a[i])/a[1];
    }
    cout << ans << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while  (test--)
    {
        solve();
    }
    return 0;
}
