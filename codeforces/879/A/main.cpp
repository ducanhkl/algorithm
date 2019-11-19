#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 100009

using namespace std;

struct data
{
    int s; int d;
} a[maxn];
int n;

int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
        cin >> a[i].s >> a[i].d;
    int ans = a[1].s;
    for (int i = 2; i <= n; i++)
        {
            if (a[i].s > ans)
            {
                ans = a[i].s;
                continue;
            }
            int t = (ans - a[i].s)/a[i].d+1;
            ans = t*a[i].d + a[i].s;
        }
    cout << ans;
	return 0;
}
