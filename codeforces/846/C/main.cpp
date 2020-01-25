#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

long long _a[maxn], *a = _a + 1, ans = LONG_LONG_MIN;
int n, delim1, delim2, delim3;
pair <long long, int> l[maxn], r[maxn];

long long calc(int l, int r)
{
    if (l == r)
        return 0;
    return a[r-1] - a[l-1];
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    for (int i = 0; i < maxn; i++)
        l[i].first = r[i].first = LONG_LONG_MIN;
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    a[-1] = 0;
    for (int i = 1; i <= n; i++)


        a[i] += a[i-1];
    for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= i; j++)
                if (calc(0, j) - calc(j, i) > l[i].first)
            {
                l[i].first = - calc(j, i) + calc(0, j);
                l[i].second = j;
            }
            for (int j = i; j <= n; j++)
                if (calc(i, j) - calc(j, n) > r[i].first)
            {
                r[i].first = calc(i, j)-calc(j, n);
                r[i].second = j;
            }
        }
    for (int i = 0; i <= n; i++)
        if (ans < r[i].first + l[i].first)
    {
        delim3 = r[i].second;
        delim1 = l[i].second;
        delim2 = i;
        ans = r[i].first + l[i].first;
    }
    //cout << ans << endl;
    cout << delim1 << " " << delim2 << " " << delim3;
    return 0;
}
