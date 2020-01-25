#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

long long a[maxn], f[maxn];
int n;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i < maxn; i++)
        f[i] = 1234567899;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[n+i] = a[i];
    long long t = 0;
    for (int i = 1; i <= n; i++)
        t += a[i], f[n+1] = min(f[n+1], t);
    if (t < 0)
        return cout << 0, 0;
    for (int i = n; i >= 2; i--)
        f[i] = min(f[i+1] + a[i], a[i]);
    int ans = 0;
    for (int i = 2; i <= n+1; i++)
        if (f[i] > 0)
            ans ++;
    cout << ans;
    return 0;
}
