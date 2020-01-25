#include <bits/stdc++.h>

using namespace std;

long long n, k, m, d, ans = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> m >> d;
    for (int i = 0; i < d && k*i + 1 < n; i++)
        ans = max(ans, (i+1)*min(m, n/(k*i+1)));
    cout << ans;
    return 0;
}
