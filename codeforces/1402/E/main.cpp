#include <bits/stdc++.h>

using namespace std;

const int maxn = 1200;

const long long mod = 998244353;

typedef pair <int, int> pii;

int n, m;
long long sum = 0, sumx = 0, sumy= 0 ;
long long dp[maxn*maxn];
int a[maxn][maxn];
vector <pii> v;

bool cmp(pii x, pii y)
{
    return a[x.first][x.second] < a[y.first][y.second];
}

long long fast_pow(long long x, long long y)
{
    if (y == 0)
        return 1;
    if (y == 1)
        return x%mod;
    long long res = fast_pow(x, y/2);
    res = res*res;
    res %= mod;
    if (y%2)
        return res*x % mod;
    return res;
}

long long inv(long long x)
{
    return fast_pow(x, mod-2);
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    v.push_back({0, 0});
    a[0][0] = -1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            v.push_back({i, j});
        }
    }
    int r, c;
    cin >> r >> c;
    sort(v.begin(), v.end(), cmp);
    int last = 1;
    for (int i = 1; i <= m*n; i++)
    {
        if  (cmp(v[i-1], v[i]))
        {
            for (; last < i; last ++)
            {
                long long x = v[last].first;
                long long y = v[last].second;
                sum = (sum + x*x%mod + y*y%mod + dp[last]%mod)%mod;
                sumx = (sumx - 2*x + 2*mod)%mod;
                sumy = (sumy - 2*y + 2*mod)%mod;
            }
        }
        long long x = v[i].first;
        long long y = v[i].second;
        dp[i] =(sum + sumx*x%mod  + sumy*y%mod + (x*x%mod +y*y%mod)*(last-1)%mod)*inv(last-1)%mod;
        dp[i] %= mod;
        if (x == r && y == c)
        {
            cout << dp[i];
            return 0;
        }
    }
    return 0;
}
