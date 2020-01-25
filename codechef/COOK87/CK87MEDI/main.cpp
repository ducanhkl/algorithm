#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

int t;

int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> t;
	while (t --)
    {
        int n, a[1001], k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= k; i++)
            a[n+i] = 1001;
        sort(a+1, a+n+k+1);
        cout << a[(n+k)/2 + 1] << endl;
    }
	return 0;
}
