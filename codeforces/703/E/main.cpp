#include <bits/stdc++.h>
#define maxn 1010

using namespace std;

long long n, k, cnt = 0;
long long a[maxn], v[maxn];
pair<int, int> trace[maxn][maxn*7];
pair <long long,long long> f[maxn][7*maxn];
map <long long, int> p;

int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 1; j <= sqrt(k); j++)
        if (k%j == 0)
            {
                v[++cnt] = j;
                if (1LL*j*j != k)
                    v[++cnt] = k/j;
            }
    sort(v+1, v+cnt+1);
    for (int i = 1; i <= cnt; i++)
        p[v[i]] = i;
    for (int i = 1; i <= cnt; i++)
    f[0][i] = {INT_MAX, 0};
    f[0][1] = {0, 0};
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= cnt; j++)
        {
            f[i][j] = f[i-1][j];
            trace[i][j] = trace[i-1][j];
        }
        for (int j = 1; j <= cnt; j++)
        {
            long long ucln = __gcd(v[j], a[i]);
            long long bonus = v[j]/ucln;
            if (f[i][j] > (pair<long long, long long>){f[i-1][p[bonus]].first +1, f[i-1][p[bonus]].second})
            {
                f[i][j] = (pair<long long, long long>){f[i-1][p[bonus]].first +1, f[i-1][p[bonus]].second};
                trace[i][j].first = 1;
            }
        }
    }
    cout << f[n][cnt].first << endl;;
    int vt = cnt;
    for (int i = n; i >= 1; i--)
    {
        if (trace[i][vt] != vt)
        {
            cout << p[vt] << " ";
            vt = trace[i][vt];
        }
    }
    return 0;
}
