#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

ll x;
bool check(ll x)
{
    int d[15];
    memset(d, 0, sizeof(d));
    int t = 0;
    while(x != 0)
        d[++t] = x%10, x /= 10;
    for (int i = 1; i <= t; i++)
        if (d[i] != d[t-i+1])
            return false;
    return true;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> x;
	while(x%10 ==0) x /= 10;
	if(check(x))
        return cout << "YES", 0;
    cout << "NO";
	return 0;
}
