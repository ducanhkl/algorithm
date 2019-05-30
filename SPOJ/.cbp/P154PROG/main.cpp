#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000006

using namespace std;

int n, k;
pii a[maxn];

bool cmp(pii x, pii y)
{
    if (x.first == y.first)
        return x.second > y.second;
    return x.first < y.first;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        a[2*i-1].first = l, a[2*i-1].second = 1;
        a[2*i].first = r, a[2*i].second = -1;
    }
    sort (a+1, a+2*n+1, cmp);
    ll l = a[1].first, dem = 1, res = 0;
    for (int i = 2; i <= 2*n; i++)
    {
        if (dem == 0)
            l = a[i].first;
        dem += a[i].second;
        if (dem == 0)
            res += a[i].first - l + 1;
    }
    if (res%k == 0)
        return cout << 0, 0;
    else cout << k - (res%k), 0;
	return 0;
}
