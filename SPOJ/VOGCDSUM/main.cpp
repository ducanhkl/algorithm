#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9+7;
const int maxn = 1e5+100;

int n;
long long a[maxn], p[maxn][40];
long long ans = 0;

long long getgcd(int l, int r)
{
    int len = (r-l+1);
    int po = log2(len);
    return __gcd(p[r][po], p[l+(1<<po)-1][po]);
}

int getnewpos(int pos, int idx)
{
    int l = pos, r = idx, res = l;
    long long valgcd = getgcd(pos, idx);
    while (l <= r)
    {
        int mid = (l+r)>>1;
        long long midval = getgcd(mid, idx);
        if (midval > valgcd)
            r = mid-1;
        else
            res = mid, l = mid+1;
    }
    return res;
}

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        if (i == 4)
        {
            n++;

            n--;
        }
        int pos = 1;
        while (pos <= i)
        {
            int pos1 = getnewpos(pos, i);
            long long val = getgcd(pos, i);
            ans = (ans + (val*(pos1-pos+1)%mod))%mod;
            pos = pos1+1;
        }
    }
    cout << ans;
}

void init()
{
    for (int j = 1; (1<<j) <= n; j++)
    {
        for (int i = n; i - (1<<j) + 1 >= 0; i--)
        {
            p[i][j] = __gcd(p[i][j-1], p[i-(1<<(j-1))][j-1]);
        }
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        p[i][0] = a[i];
    }
    init();
    solve();
    return 0;
}
