#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

vector <pii> v;
ll ans = 0, t;
int n, x, y, z;

int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> x >> y >> z;
	t = n*x;
	for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, y-x});
        v.push_back({b, z-y});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        t += v[i].second, ans = max(t, ans);
    cout << ans;
	return 0;
}
