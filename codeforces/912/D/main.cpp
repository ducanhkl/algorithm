#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair <ll, ll> ii;
typedef pair <ll, ii> pii;

const int maxn = 2e5;

int n, m, r, k;
long long x[maxn], y[maxn];
priority_queue <pii> q;
long long ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> r >> k;
    for (int i = 1; i <= n; ++i)
    {
        int l, rr;
        l = max(i-r+1, 1);
        rr = min(n-r+1, i);
        x[i] = rr-l+1;
    }
    for (int i = 1; i <= m; i++)
    {
        int l, rr;
        l = max(i-r+1, 1);
        rr = min(m-r+1, i);
        y[i] = rr-l+1;
    }
    sort(x+1, x+n+1);
    sort(y+1, y+m+1);
    for (int i = 1; i <= n; i++)
        q.push({x[i]*y[m], {i, m}});
    while (k--)
    {
        pii t = q.top();
        q.pop();
        long long l = t.first;
        ii p = t.second;
        ans += l;
        if (p.second == 1)
            continue;
        q.push({x[p.first]*y[p.second-1], {p.first, p.second-1}});
    }
    long double res = (long double) ans / ((ll)(n-r+1)*(m-r+1));
    cout << fixed << setprecision(10) << res;
    return 0;
}
