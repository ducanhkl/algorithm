#include <bits/stdc++.h>
#define maxn 2000

using namespace std;

int n;
long long ans = 0;

struct data
{
    double x;
    double y;
    long long s;
} a[maxn];

long long sqr(long long x)
{
    return x*x;
}
double calc(data p1, data p2)
{
    if (p2.x < p1.x)
        return calc(p2, p1);
    return (p2.y-p1.y)/(p2.x-p1.x);
}
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        long long res = 0;
        map <double, long long> m;
        for (int j = 1; j <= n; j++)
            if (j != i)
        {
            double t = calc(a[i], a[j]);
            m[t] += sqr(a[j].s) + 5;
            res = max(res, m[t]);
        }
        ans = max(ans, res+ sqr(a[i].s) + 5);
    }
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].x >> a[i].y >> a[i].s;
    solve();
    cout << ans;
    return 0;
}
