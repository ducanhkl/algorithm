#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int n;
long long a[maxn], s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = INT_MIN;
    a[n+1] = INT_MAX;
    sort (a+1, a+n+1);
    int t = n/2+1;
    if (a[t] == s)
        return cout << 0, 0;
    if (a[t-1] <= s && a[t+1] >= s)
        return cout << abs(s-a[t]), 0;
    if (a[t+1] < s)
    {
        long long ans = 0;
        for (int i = t; i <= n && a[i] < s; i++)
            ans += s - a[i];
        cout << ans;
        return 0;
    }
    if (a[t-1] > s)
    {
        long long ans = 0;
        for (int i = t; i >= 1 && a[i] > s; i --)
            ans += a[i] -s;
        cout << ans;
        return 0;
    }
    return 0;
}
