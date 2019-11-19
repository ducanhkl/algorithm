#include <bits/stdc++.h>

using namespace std;

long double m, ans = 0;
pair <long double, long double > a[100001];
int n;

bool cmp(pair <long double, long double > x, pair <long double, long double > y)
{
    return (x.first/x.second) < (y.first/y.second);
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a+1, a+n+1, cmp);
    ans = m*(a[1].first/a[1].second);
    cout << fixed << setprecision(6) << ans;
    return 0;
}
