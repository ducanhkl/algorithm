#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 3000005

using namespace std;

set <int> s;
int n, a[maxn], dd[maxn], ans = 0;

int main()
{
    memset(dd, 0, sizeof(dd));
    freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        s.insert(a[i]);
        dd[a[i]] = true;
        for (set <int>::iterator it = s.begin(); it != s.end(); it++)
            s.insert(a[i] | (*it)), dd[a[i]|(*it)] = 1;
    }
    for (int i = 0; i <= 3000000; i++)
        if (dd[i])
            ans ++;
    cout << ans;
	return 0;
}
