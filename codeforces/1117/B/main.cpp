#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+100;
int n, m, k;
long long a[maxn], ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1, greater <long long>());
    ans = (m/(k+1))*a[1]*k;
    ans += (m%(k+1))*a[1];
    ans += (m/(k+1))*a[2];
    cout << ans;
    return 0;
}
