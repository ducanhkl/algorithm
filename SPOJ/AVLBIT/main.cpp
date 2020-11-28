#include <bits/stdc++.h>

using namespace std;

const long long maxn = 100010;

class spare_table
{

long long table[maxn][20];
public:
    void build(long long a[], long long len, long long ff(long long, long long))
    {
        memset(table, 0, sizeof(table));
        for (long long i = 1; i <= len; i++)
            table[i][0] = a[i];
        for (long long j = 1; (1<<j) <= len; j++)
        {
            for (long long i = 1; i + (1<<j)-1 <= len; i++)
            {
                table[i][j] = ff(table[i][j-1], table[i+(1<<(j-1))][j-1]);
            }
        }
    }

    long long get(long long l, long long r, long long ff(long long, long long))
    {
        long long j = log2(r-l+1);
        return ff(table[l][j], table[r-(1<<j)+1][j]);
    }

};


spare_table min_table, max_table, gcd_table, pos_table;

long long a[maxn], n, b[maxn];
map <long long, long long> idx;
long long vt_r[maxn];

long long f_min(long long x, long long y)
{
    return min(x, y);
}


long long f_max(long long x, long long y)
{
    return max(x, y);
}


long long f_gcd(long long x, long long y)
{
    return __gcd(x, y);
}

void solve(long long x, long long y)
{
    long long sub = max_table.get(x, y, f_max) - min_table.get(x, y, f_min);
    long long len = y-x+1;
    if (sub % (len-1))
    {
        cout << "NO" << endl;
        return;
    }
    long long dis = sub/(len-1);
    long long gcd = abs(gcd_table.get(x, y-1, f_gcd));
    if (dis != gcd)
    {
        cout << "NO" << endl;
        return ;
    }
    long long pos = pos_table.get(x, y, f_max);
    if (pos <= y)
    {
        cout << "NO" << endl;
        return ;
    }
    cout << "YES" << endl;
    return ;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    long long n, q;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (long long i = 1; i <= n; i++)
        vt_r[i] = maxn+100;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
        long long pos = idx[a[i]];
        if (pos > 0)
            vt_r[pos] = i;
        idx[a[i]] = i;
    }
    for (long long i = 1; i < n;  i++)
    {
        b[i] = a[i+1] - a[i];
    }
    max_table.build(a, n, f_max);
    min_table.build(a, n, f_min);
    gcd_table.build(b, n-1, f_gcd);
    pos_table.build(vt_r, n, f_min);
    for (long long i = 1; i <= q; i++)
    {
        long long x, y;
        cin >> x >> y;
        solve(x, y);
    }
    return 0;
}
