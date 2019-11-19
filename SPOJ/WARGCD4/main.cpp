#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000004
#define reset(a) memset(a, 0, sizeof(a));
using namespace std;

int a[maxn];
int n;
ll dd[maxn], dp[maxn];

ll tinh(ll k)
{
    if (k < 4)
        return 0;
    else return k*(k-1)*(k-2)*(k-3)/24;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	while (cin >> n)
    {
        reset(dd);
        reset(dp);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            dd[a[i]] ++;
        int k = *max_element(a+1, a+n+1);
        for (int i = 1; i <=  k; i++)
            for (int j = 2*i; j <= k; j += i)
                dd[i] += dd[j];
        for (int i = k; i >= 1; i--)
            if (dd[i] != 0)
        {
            dp[i] = tinh(dd[i]);
            for (int j = 2*i; j <= k; j += i)
                dp[i] -= dp[j];
        }
        cout << dp[1] << endl;
    }
	return 0;
}
