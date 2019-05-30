#include <bits/stdc++.h>

using namespace std;

typedef pair <long long, long long > pii;
const long long  maxn = 1e5+100;

long long  n;
long long m;
pii a[maxn];
long long b[maxn], s[maxn], A, cm, cf;

bool cmp_by_pos(pii x, pii y)
{
    return x.second < y.second;
}

void solve()
{
    long long ans = 0;
    long long res1 = 0, posres2 = n+1;
    sort (a+1, a+n+1);
    for (long long  i = 1; i <= n; i++)
        s[i] = s[i-1] + a[i].first, b[i] = a[i].first;
    b[n+1] = A;
    long long mm = m;
    for (long long  i = n+1; i >= 1; i--)
    {
        if (A - b[i] > mm)
            break;
        mm -= A - b[i];
        s[i] += A-b[i];
        b[i] = A;
        long long  l = 1, r = A;
        long long res = 0;
        while (l <= r)
        {
            long long val1 = 0;
            long long mid = (l+r)>>1;
            long long  pos = lower_bound(b+1, b+n+1, mid) - b - 1;
            pos = min(pos, n);
            val1 = mid*pos-s[pos];
            if (val1 <= mm)
                res = mid, l = mid+1;
            else
                r = mid-1;
        }
        long long val = cf*(n-i+1) + cm*res;
        if (ans < val)
        {
            res1 = res;
            posres2 = i;
            ans = val;
        }
    }
    cout << ans <<endl;
    for (long long  i = 1; i <= n; i++)
        if (a[i].first < res1)
            a[i].first = res1;
    for (long long  i = n; i >= posres2; i--)
        a[i].first = A;
    sort(a+1, a+n+1, cmp_by_pos);
    for (long long  i = 1; i <= n; i++)
        cout << a[i].first << " ";
}

int  main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin  >> n >> A >> cf >> cm >> m;
    for (long long  i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    solve();
    return 0;
}
