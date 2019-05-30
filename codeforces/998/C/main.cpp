#include <bits/stdc++.h>
#define maxn 400000

using namespace std;


char a[maxn];
long long x, y, dem = 0, n;
long long ans = LONG_LONG_MAX;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] -= '0';
    a[0] = 1;
    for (int i = 1; i <= n; i++)
        if (a[i] == 0 && a[i-1] == 1)
            dem ++;
    for (int i = 0; i < dem; i++)
        ans = min(ans, x*i + y*(dem-i));
    if (ans == LONG_LONG_MAX)
        return cout << 0, 0;
    cout << ans;
    return 0;
}
