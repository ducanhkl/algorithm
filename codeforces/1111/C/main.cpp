#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n, k;
long long x1, x2;
int a[maxn];

long long get(long long l, long long r)
{
    return upper_bound(a+1, a+k+1, r) - lower_bound(a+1, a+k+1, l);
}

long long solve(long long l, long long r)
{
    if (!get(l, r))
        return x1;
    if (l == r)
    {
        return x2*get(l, r);
    }
    int cnt = get(l, r);
    long long ans = x2*(r-l+1)*(cnt);
    long long mid = (l+r)>>1;
    long long res1 = solve(l, mid);
    long long res2 = solve(mid+1, r);
    res1 += res2;
    ans = min(ans, res1);
    return ans;
}

int main()
{
    //freopen("inp.txt", "r", stdin);;
    ios_base::sync_with_stdio(false);
    cin >> n >> k >> x1 >> x2;
    for (int i = 1; i <= k; i++)
        cin >> a[i];
    sort(a+1, a+k+1);
    long long l = 1, r = 1LL<<n;
    cout << solve(l, r);
    return 0;
}
