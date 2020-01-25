#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define maxn 1000006
#define reset(a) memset(a, 0, sizeof(a))
using namespace std;
int n;
ll l[maxn], ans = 0, d[maxn], a[maxn], dd[maxn];
int main()
{
    reset(l);
    reset(d);
    reset(dd);
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int np = 0;
    for (int i = 1; i <= n; i++)
        {
            d[++np] = a[i], dd[np] = 1;
            while (np>1 && d[np] > d[np-1])
                d[np-1] = d[np], dd[np-1] += dd[np], np--;
            l[i] = dd[np]*a[i] + l[i-dd[np]], ans += l[i];
        }
    np = 0;
    for (int i = 1; i <= n; i++)
        {
            d[++np] = a[i], dd[np] = 1;
            while (np>1 && d[np] < d[np-1])
                d[np-1] = d[np], dd[np-1] += dd[np], np--;
            l[i] = dd[np]*a[i] + l[i-dd[np]], ans -= l[i];
        }
    cout << ans;
    return 0;
}
