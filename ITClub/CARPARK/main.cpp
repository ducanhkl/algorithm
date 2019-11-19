#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000006

using namespace std;

ll  dd[maxn], a[maxn], ans = 0;
int n;

int main()
{
    int t;
    freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> t;
	while (t--)
    {
        ans = 0;
        memset(dd, 0,sizeof(dd));
        a[0] = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a+1, a+n+1);
        for (int i = 1; i < n; i++)
            dd[i] = a[i+1] - a[i];
        for (int i = 1; i < n; i ++)
            ans += dd[i];
        cout << 2*ans << endl;
    }
	return 0;
}
