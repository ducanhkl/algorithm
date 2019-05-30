#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000006
using namespace std;
int n, k, a[maxn], dem = 0;

bool findm(int x, int l, int r)
{
    int g;
    while(l < r)
    {
        g = (l+r)/2;
        if (a[g] == x || a[l] == x || a[r] == x)
            return 1;
        if (a[g] > x)
            r = g;
        else l = g+1;
    }
    return 0;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1,a +n+1);
    for (int i = 1; i <= n; i++)
        if (findm(a[i]+k, i, n))
            dem ++;
    cout << dem;
	return 0;
}
