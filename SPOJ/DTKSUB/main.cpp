#include <bits/stdc++.h>
#define maxn 1000006
#define BASE1 256
#define BASE2 257

using namespace std;
const long long MOD = 10000009;
long long h1[maxn], h2[maxn], p1[maxn], p2[maxn], a[maxn];
int n, k, ans = 0;
vector <pair <long long, long long > > d;

long long get1 (int x, int y)
{
    return (h1[x+y-1] - h1[x-1]*p1[y] + MOD*MOD)%MOD;
}
long long get2 (int x, int y)
{
    return (h2[x+y-1] - h2[x-1]*p2[y] + MOD*MOD)%MOD;
}
bool check (int x)
{
    d.resize(0);
    //cout << d.size() << endl;
    for (int i = 1; i <= n-x+1; i++)
    {
        long long res1 = get1(i, x);
        long long res2 = get2(i, x);
        d.push_back({res1, res2});
        //cout << res1 << " " << res2 << endl;
    }
    sort(d.begin(), d.end());
    int dem = 1;
    for (int i = 1; i < d.size(); i++)
        if (d[i] == d[i-1])
    {
        dem ++;
        if (dem >= k)
            return true;
    } else dem = 1;
    return false;
}
int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    //if (k == 1)
        //return cout << n, 0;
    p1[0] = p2[0] = 1;
    memset(h1, 0, sizeof(h1));
    memset(h2, 0, sizeof(h2));
    for (int i = 1; i < maxn; i++)
        p1[i] = (p1[i-1]*BASE1)%MOD, p2[i] = (p2[i-1]*BASE2)%MOD;
    for (int i = 1; i <= n; i++)
    {
        char x;
        cin >> x;
        a[i] = (int)(x-'a');
        h1[i] = (h1[i-1]*BASE1 + a[i])%MOD;
        h2[i] = (h2[i-1]*BASE2 + a[i])%MOD;
    }
    int l = 0, r = maxn;
    while (l <= r)
    {
        int mid = (l+r)/2;
        if (check (mid))
            l = mid + 1, ans = max(ans, mid);
        else r = mid - 1;
    }
    cout << ans;
    return 0;
}
