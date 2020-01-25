#include <bits/stdc++.h>
#define maxn 200

using namespace std;

long long f[maxn][maxn][maxn];
pair <long long, long long> a[maxn];
int n;
const long long max_num = 1234567891011;

bool check(long long res)
{
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            for (int k = 0; k < maxn; k++)
                f[i][j][k] = max_num;
    f[0][0][0] = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            for (int k = 0; k+j <= i; k++)
    {
        if (f[i][j][k] == max_num)
            continue;
        if (a[i].first == a[i+1].first)
        {
            f[i+1][j][k+1] = min(f[i+1][j][k+1], f[i][j][k] + a[i+1].first - a[i+1].second*res);
            if (j>0)
                f[i+1][j-1][k] = min(f[i+1][j-1][k], f[i][j][k]);
        }   else
        {
            f[i+1][j+k][1] = min(f[i+1][j+k][1], f[i][j][k] + a[i+1].first - a[i+1].second*res);
            if (j+k> 0)
                f[i+1][j+k-1][0] = min(f[i+1][j+k-1][0], f[i][j][k]);
        }
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j+i <= n; j++)
            if (f[n][i][j] <= 0)
                return 1;
    return 0;
}

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first;
    for (int i = 1; i <= n; i++)
        cin >> a[i].second, a[i].first*=1000;
    sort(a+1, a+n+1, greater<pair<long long, long long> > ());
    long long l = 0, r = 1144, mid, ans;
    while (l <= r)
    {
        mid = (l+r)>>1;
        if (check(mid))
            ans = mid, r = mid - 1;
        else
            l = mid+1;
    }
    cout << ans;
}

