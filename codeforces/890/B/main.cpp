#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 100005
using namespace std;

int a[2*maxn + 5], dd[2*maxn+5];
int maxx, n;

int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
        cin >> a[i];
    maxx = a[1];
    memset(dd, 0, sizeof(dd));
    for (int i = 1; i <= n; i++)
        dd[a[i]] = i;
    for (int i = 1; i <= 2*maxn; i++)
        if (dd[i] != 0 && dd[i] < dd[maxx])
            maxx = i;
    cout << maxx;
	return 0;
}
