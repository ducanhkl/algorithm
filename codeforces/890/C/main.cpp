#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

int n, ans = 0;

int main()
{
    map <int, bool> t;
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (t[x])
        {
            t[x] = 0;
            t[i] = 1;
        } else{
            t[i] = 1;
            ans ++;
        }
    }
    cout << ans;
	return 0;
}
