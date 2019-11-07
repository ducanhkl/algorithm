#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const int maxn = 1e6+100;

struct point
{
    long long x, y, v;
} a[maxn];

int n;
int q[maxn];
long long dp[maxn];

ld ctan(int i, int j)
{
    return (ld)(dp[i] - dp[j]) / (a[i].x-a[j].x);
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y >> a[i].v;
    sort (a+1, a+n+1, [] (point x, point y)
          {
            return x.x < y.x;
          });
    int l = 0, r = 0;
    for (int i = 1;  i <= n; i++)
    {
        while (l < r && ctan(q[l], q[l+1]) >= a[i].y)
            l++;
        int j = q[l];
        dp[i] = max(dp[i-1], dp[j] + (a[i].x - a[j].x)*a[i].y - a[i].v);
        while (l < r && ctan(q[r-1], q[r]) <= ctan(q[r], i))
            r--;
        q[++r] = i;
    }
    cout << dp[n];
    return 0;
}
