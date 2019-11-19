#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define ll long long
#define maxnum 123456789
#define maxn 3000001

using namespace std;
ll n, k, c[maxn], ans = 0;
priority_queue <pair<ll, ll> > t;
int d[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= k ; i++)
        t.push(make_pair(c[i], i));
    for (int i = k+1; i <= n+k; i++)
    {
        if (i <= n)
            t.push(mp(c[i], i));
        pair <ll, ll> x;
        x = t.top();
        t.pop();
        ans += (1LL*i - x.second)*x.first;
        d[x.second] = i;
        if (t.empty())
            break;
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
        cout << d[i] << " ";
    return 0;
}
