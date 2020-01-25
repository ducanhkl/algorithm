#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

int dx[258], dy[257];
ll ans = 0;
int n, k;

ll xuly1(int x, int y)
{
    ll t = (x+y-1);
    ll tong = t*(t+1)/2;
    if (t % 2 == 0)
        return tong-y+1;
    else return tong - x +1;
}

ll xuly2(int x, int y)
{
    x = n - x+1;
    y = n-y+1;
    return n*n*1LL - 1LL*xuly1(x, y)+1;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    dx['D'] = 1, dy['D'] = 0;
    dx['L'] = 0, dy['L'] = -1;
    dx['R'] = 0, dy['R'] = 1;
    dx['U'] = -1, dy['U'] = 0;
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> k;
	int x = 1, y = 1;
	for (int i = 1; i <= k; i++)
    {
        if (x+y > n+1)
            ans += xuly2(x, y);
        else ans += xuly1(x, y);
        char m;
        cin >> m;
        x += dx[m], y +=dy[m];
    }
    if (x+y > n+1)
        ans += xuly2(x, y);
    else ans += xuly1(x, y);
    cout << ans;
	return 0;
}
