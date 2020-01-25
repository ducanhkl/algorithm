#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e6+100;
typedef pair <long long, long long> ii;

ii a[maxn];
int n, k;
long long ans = 0;

bool cmp(ii x, ii y)
{
    return x.first-x.second<y.first-y.second;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first;
    for (int i = 1; i <= n; i++)
        cin >> a[i].second;
    sort(a+1, a+n+1, cmp);
    for (int i = 1; i <= k; i++)
        ans += a[i].first;
    for (int i = k+1; i <= n; i++)
        ans += a[i].second;
    cout << ans;
    return 0;
}
