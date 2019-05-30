#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000005

using namespace std;

int a[maxn], d[maxn], m = 0, n, k, ans = 0;
pii b[maxn];
int t1[maxn], t2[maxn];

void init()
{
    sort(b, b+n+1);
    for (int i = 0; i <= n; i++)
    {
        if (!i || b[i].first != b[i-1].first)
            m++;
        d[m] = b[i].first, a[b[i].second] = m;
    }
}
int get1(int x)
{
    int res = 1e9;
    for (; x < n+1; x += x&(-x))
        res = min(res, t1[x]);
    return res;
}
int get2(int x)
{
    int res = -1e9;
    for (; x < n+1; x+= x&(-x))
        res = max(res, t2[x]);
    return res;
}
void update1(int x, int value)
{
    for (;x > 0; x -= x&(-x))
        t1[x] = min(t1[x], value);
}
void update2(int x, int value)
{
    for (;x > 0; x -= x&(-x))
        t2[x] = max(t2[x], value);
}
bool check(int x)
{
    for (int i = 0; i < maxn; i++)
        t2[i] = -1e9, t1[i] = 1e9;
    update1(a[0], 0), update2(a[0], 0);
    int mi, ma;
    for (int i = 1; i <= n; i++)
    {
        int tmp = lower_bound(d+1, d+m+1,d[a[i]]- x)-d;
        mi = get1(tmp)+1, ma = get2(tmp)+1;
        update1(a[i], mi), update2(a[i], ma);
    }
    return mi <=k && ma >= k;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        a[i] += a[i-1];
        b[i].first = a[i];
        b[i].second = i;
    }
    init();
    int mid, l =-1e9, r = 1e9;
    while (l <= r)
    {
        mid = (l+r)/2;
        if (check(mid))
        {
            ans = mid;
            r = mid -1;
        } else l = mid+1;
    }
    cout << ans;
	return 0;
}
