#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;

int n;
long long s1, s2, a[maxn];


bool check(long long x)
{
    long long l = a[n] - x, r = a[n] + x;
    for (int i = n-1; i >= 1; i--)
    {
        if (l <= a[i] && a[i] <= r)
        {
            l = a[i] - x;
            r = a[i] + x;
        } else
        {
            l = max(l, a[i] - x);
            r = min(r, a[i] + x);
        }
    }
    return (l <= s1 && s1 <= r) || (l <= s2 && s2 <= r);
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> s1 >> s2;
    if (s2 < s1)
        swap(s1, s2);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    long long l =  s2 - s1, r = 1e12, ans = l;
    while (l <= r)
    {
        long long mid = (l+r)>>1;
        if (check(mid))
            ans = mid, r = mid-1;
        else
            l = mid+1;
    }
    cout << ans;
    return 0;
}
