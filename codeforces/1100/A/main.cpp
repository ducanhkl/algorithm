#include <bits/stdc++.h>

using namespace std;

int n, k, ans = 0, res = 0;
int a[200];

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i], res += (int)(a[i] == 1);
    int e = n-res;
    for (int i = 1; i <= n; i++)
    {
        int now = res, ee = e;
        for (int j = i; j >= 1; j -= k)
            {
                now -= (int)(a[j] == 1);
                ee -= (int)(a[j] == -1);
            }
        for (int j = i+k; j <= n; j += k)
            {
                now -= (int)(a[j] == 1);
                ee -= (int)(a[j] == -1);
            }
        ans = max(ans, abs(now - ee));
    }
    cout << ans;
    return 0;
}
