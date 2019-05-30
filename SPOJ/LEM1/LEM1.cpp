#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 100004

using namespace std;

const long double PI = 3.141592653589793238L;
long double a[maxn], mid, t, l, r;
int n;

long double calc(long double x, long double y, long double z)
{
    return acos((x*x+y*y-z*z)/(2*x*y));
}
long double check(long double k)
{
    long double c = 0;
    for (int i = 1; i <= n; i++)
        c += calc(a[i-1] + k, a[i]+k, a[i]+a[i-1]);
    return c;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
        cin >> a[i], t += a[i];
    a[0] = a[n];
    l = 0, r = t;
    mid = (r+l)/2;
    while (l != mid && r != mid)
    {
        long double g = check(mid);
        if (g == 2*PI) break;
        if (g > 2*PI)
            l = mid;
        else r = mid;
        mid = (l+r)/2;
    }
    cout << fixed << setprecision(3) << mid;
	return 0;
}
