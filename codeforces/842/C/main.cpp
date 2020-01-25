#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000006
using namespace std;

int a[maxn];
int x, y, n;
vector <int> g[maxn];
set <int> t[maxn];

void dfs(int v, int d, int b)
{
    for (set <int>::iterator w = t[d].begin(); w!= t[d].end(); w++)
        t[v].insert(__gcd(*w, a[v]));
    t[v].insert(b), t[v].insert(__gcd(b, a[v]));
    b = __gcd(b, a[v]);
    for (vector <int>::iterator w = g[v].begin(); w != g[v].end(); w++)
        if(*w != d)
            dfs(*w, v, b);
}
int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n-1; i++)
    {
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1, 0, 0);
    for (int i = 1; i <= n; i++)
        cout << *t[i].rbegin() << " ";
	return 0;
}
