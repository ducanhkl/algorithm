#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n, m, k;
long double a[maxn], t, ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    int pos;
    for (pos = 1; pos <= n && m != 0; pos ++, m--);
    if (pos > n)
        pos --, m++;
    for (int i = pos; i <= n; i++)
    {
        ans += a[i] + min(k, m);
        m = max(0, m-k);
    }
    t = ans/(n-pos+1);
    while (pos >= 1)
    {
        if ((ans+a[pos-1]+min(k, m))/(n-pos+2) > t)
            ans += a[pos-1]+min(k, m), pos--;
        else
            break;
        m = max(0, m-k);
    }
    cout << fixed << setprecision(10) << ans/(n-pos+1);
    return 0;
}
