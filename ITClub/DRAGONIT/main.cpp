#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 100005

using namespace std;

pii a[maxn];
int dd[maxn];
ll n, s;
int main()
{
    memset(dd, 0, sizeof(dd));
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> s >> n;
	int dem = 0;
	for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    for (int i = 1; i <= n; i++)
        if (a[i].first < s && dd[i] == 0)
    {
        s += a[i].second;
        dd[i] = 1;
        i = 0;
    }
    for (int i =1; i <=n; i++)
        if (dd[i])
            dem ++;
    if (dem == n)
        cout << "YES";
    else cout << "NO";
	return 0;
}
