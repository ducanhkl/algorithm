#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define maxn 1001

using namespace std;

ll a[maxn][maxn], f[maxn], ans = LONG_LONG_MIN;
int n;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    f[1] = 0;
    for (int i = 1; i <= n; i++)
        f[1] += a[i][i];
    for (int i = 2; i <= n; i++)
        f[i] = LONG_LONG_MIN+10;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            f[i] = max(f[i], f[j] - a[j][1] + a[j][i] + a[i][1] - a[i][i]), ans = max(ans, f[i]);
    cout << ans;
    return 0;
}
