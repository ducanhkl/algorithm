#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 100006
using namespace std;
int a[maxn], n, m, b[maxn];
pii v[maxn];

void update()
{
    sort(v+1, v+n+1);

}
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            v[i].first = a[i];
            v[i].second = i;
        }
    update();

	return 0;
}
