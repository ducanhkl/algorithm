#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	int t;
	cin >>t ;
	while(t--)
    {
        ll ans = 0;
        ll n;
        cin >> n;
        for (int i = 1; i <= 700; i ++)
            {
                if (n - i == 0)
                    break;
                ans += sqrt(n-i);
            }
        cout << ans << endl;
    }
	return 0;
}
