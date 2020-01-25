#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;


int n, c;
long long a[maxn], dp[maxn], tong = 0;
multiset <long long> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> c;
    for (int i = 1; i <= n; i++)\
        cin >> a[i];
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        tong += a[i];
        s.insert(a[i]);
        if (i > c)
            s.erase(s.find(a[i-c])), tong -= a[i-c];
        dp[i] = dp[max(i-c, 0)] + tong;
        if (s.size() == c)
            dp[i] -= *s.begin();
        dp[i] = min(dp[i], dp[i-1] + a[i]);
    }
    cout << dp[n];
    return 0;
}
