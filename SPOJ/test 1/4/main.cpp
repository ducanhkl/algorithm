#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000005
using namespace std;

int a[maxn], d[maxn];
int n, ans = 0;
int main()
{
    memset(d, 0, sizeof(d));
    freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	int j;
	for (int i = 1; i <= n; i++)
        cin >> a[i], d[a[i]] ++;
    for (int i = 6001; i >= 0; i--)
        if (d[i] > 0)
            {
                j = i-1;
                ans ++;
                break;
            }
    for (; j >= 0; j --)
        ans += min(d[j], 2);
    cout << ans;
	return 0;
}
