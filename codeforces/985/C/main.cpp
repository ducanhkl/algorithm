#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int n, k, l, pos;
long long a[maxn];
long long ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> l;
    for (int i = 1; i <= n*k; i++)
        cin >> a[i];
    sort(a+1, a+n*k+1);
    for (int i = 1; i <= n*k; i++)
        if (a[i] - a[1] <= l)
            pos = i;
    if (pos < n)
        return cout << "0", 0;
    int l = 1, f = pos-n+1;
    for (int i = 1; i <= n; i++)
    {
        if (l < f)
            ans += a[l];
        else ans += a[f];
        f++;
        if (l+k-1 >= f && l < f)
            l = k-(f-l)+pos;
        else
            if (l == f)
                l = pos + k-1;
            else
                l += k;
    }
    cout << ans;
    return 0;
}
