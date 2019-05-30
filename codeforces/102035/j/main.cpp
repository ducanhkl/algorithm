#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n;
long long a[maxn], mx1[maxn], mx2[maxn], ans1[maxn], ans2[maxn], m;

int main()
{
    //freopen("inp.txt", "r", stdin);
    for (int i = 0; i < maxn; i++)
        mx1[i] = mx2[i] = ans1[i] = ans2[i] = LONG_MIN;
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        if (mx1[i-1] < 0)
            mx1[i] = a[i];
        else
            mx1[i] = a[i] + mx1[i-1];
    }
    for (int i = n; i >= 1; i--)
    {
        if (mx2[i+1] < 0)
            mx2[i] = a[i];
        else
            mx2[i] = a[i] + mx2[i+1];
    }
    for (int i = 1; i <= n; i++)
        ans1[i] = max(mx1[i], ans1[i-1]);
    for (int i = n; i >= 1; i--)
        ans2[i] = max(mx2[i], ans2[i+1]);
    for (int i = 1; i <= n; i++)
    {
        long long ans = LONG_MIN;
        ans = max(ans, max(ans1[i-1], ans2[i+1]));
        long long k = m+max(mx1[i-1], 0LL)+max(mx2[i+1], 0LL);
        ans = max(ans, k);
        cout << ans << " ";
    }
    return 0;
}
