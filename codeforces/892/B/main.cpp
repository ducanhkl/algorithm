#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000004

using namespace std;

int n;
int a[maxn];
int ans = maxnum;
int main()
{
    //freopen("inp.txt", "r", stdin);
    int dem = 0;
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
        cin >> a[i], dem += (a[i] == 1);
    if (dem != 0)
        return cout << n-dem, 0;
    for (int i = 1; i <= n; i++)
    {
        int t = a[i];
        for (int j = i+1; j<= n; j++)
        {
            t = __gcd(t, a[j]);
            if (t == 1)
                ans = min(ans, j-i);
        }
    }
    if (ans == maxnum)
        cout << -1;
    else cout << n+ans-1;
	return 0;
}
