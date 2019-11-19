#include <bits/stdc++.h>

using namespace std;


const int maxn = 3e5+100;
int n;
long long p[maxn], s1[maxn], s2[maxn];
long long a, b, x, y, k;

long long calc(int num)
{
    long long res = 0;
    for (int i = 1; i <= num; i++)
        s2[i] = s1[i];
    sort(s2+1, s2+num+1);
    for (int i = num; i >= 1; i--)
        res += (p[n-num+i]*s2[i]/100);
    return res;
}

void solve()
{
    int ans = -1;
    for (int i = 1; i <= n; i++)
    {
        if (i%a == 0)
            s1[i] += x;
        if (i% b == 0)
            s1[i] += y;
    }
    int l = 1, r= n;
    while (l <= r)
    {
        int mid = (l+r)/2;
        if (calc(mid) >= k)
            ans = mid, r = mid-1;
        else
            l = mid+1;
    }
    cout << ans << endl;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        memset(s1, 0, sizeof(s1));
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> p[i];
        sort(p+1, p + n+1);
        cin >> x >> a >> y >> b;
        cin >> k;
        solve();
    }
    return 0;
}
