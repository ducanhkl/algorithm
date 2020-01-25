#include <bits/stdc++.h>

using namespace std;

long long n, h, res = 0, l = 0, r = 2e9+1;


bool check(long long hmax)
{
    long long k = min(h, hmax);
    long long cnt = hmax*hmax - k*(k-1)/2;
    return cnt <= n;
}

long long get(long long hmax)
{
    long long k = min(hmax, h);
    long long cnt = hmax*hmax - k*(k-1)/2;
    long long ans = 2*hmax-1 - (k-1);
    n -= cnt;
    ans += ceil((long double)n/(long double)hmax);
    return ans;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> h;
    while (l <= r)
    {
        long long mid = (l+r) >> 1;
        if (check(mid))
            res = mid, l = mid+1;
        else r = mid-1;
    }
    cout << get(res);
    return 0;
}
