#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
long long ans = 0;
int n;
int a[maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == a[i-1])
            continue;
        if (a[i] > a[i-1])
            ans += (n*1LL-a[i]+1)*(a[i]-a[i-1]);
        else
            ans += a[i]*1LL*(a[i-1]-a[i]);
    }
    cout << ans;
    return 0;
}
