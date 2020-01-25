#include <bits/stdc++.h>
#define maxn 5*100001


using namespace std;

int a[maxn], n, k, d, dd[maxn], f[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(dd, 0, sizeof(dd));
    memset(f, 0, sizeof(f));
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++)
    {
        int pos = lower_bound(a+1, a+n+1, a[i] - d) - a;
        if (pos <= i-k+1 && (pos == 1 || f[i-k] - f[pos-2] > 0))
            dd[i] = 1;
        f[i] = f[i-1] + dd[i];
    }
    if (dd[n] == 1)
        return cout << "YES", 0;
    cout << "NO";
    return 0;
}
