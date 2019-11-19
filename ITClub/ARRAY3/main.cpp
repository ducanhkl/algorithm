#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000005
using namespace std;

int n;
ll a[maxn];
int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] += a[i-1];
    int l = 1, r = n;
    int g;
    while(l < r)
    {
        g = (l+r)/2;
        if (a[g] == a[n] - a[g])
            break;
        if (a[g] > a[n]-a[g])
            r = g-1;
        else l = g+1;
    }
    g = (l+r)/2;
    int t1 =  abs(a[g+1]-a[n]+a[g+1]);
    int t2 = abs(a[g] - a[n]+a[g]);
    int t3 = abs(a[g-1]-a[n]+a[g-1]);
    int t = min(t1, min(t2, t3));
    if (t1 == t)
        return cout << g+1 << " " << n-g-1, 0;
    if (t2 == t)
        return cout << g <<  " " << n-g, 0;
    if (t3 == t)
        return cout << g-1 << " " << n-g+1, 0;
	return 0;
}
