#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000005
#define reset(a) memset(a, 0, sizeof(a))

using namespace std;

ll a[maxn], tree1[maxn], tree2[maxn];
int n;
ll res = 0;

ll get(int x)
{
    ll ans = 0;
    for (;x < maxn; x += x&(-x))
        ans += tree1[x];
    return ans;
}
void update(int x)
{
    for(; x > 0;  x -= x&(-x))
        tree1[x]++;
}
ll get2(int x)
{
    ll ans = 0;
    for (; x < maxn; x += x&(-x))
        ans += tree2[x];
    return ans;
}
void update2(int x, int y)
{
    for (; x > 0; x -= x&(-x))
        tree2[x] += y;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)
    {
         reset(tree1);
        reset(tree2);
        res = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
        {
            int k = get(a[i]+1);
            update(a[i]);
            res += get2(a[i]+1);
            update2(a[i], k);
        }
        cout << res<< endl;
    }
	return 0;
}
