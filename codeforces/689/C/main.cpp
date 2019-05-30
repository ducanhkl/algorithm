#include <bits/stdc++.h>

using namespace std;

const unsigned long long maxc = 1LL<<63, maxsqrt = 1e6+100;
unsigned long long m;
unsigned long long ans = maxc, l = 1, r = maxc;

long long calc(long long val)
{
    long long res = 0;
    for (long long i = 2; i <= maxsqrt; i++)
        res += val/(i*i*i);
    return res;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> m;
    while (l <= r)
    {
        long long mid = (l+r)>>1;
        long long res = calc(mid);
        if (res >= m)
            r = mid-1, ans = mid;
        else
            l = mid+1;
    }s
    if (calc(ans) == m)
    {
        cout << ans;
        return 0;
    }
    cout << -1;
    return 0;
}
