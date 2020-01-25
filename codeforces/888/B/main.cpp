#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

int n;

int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	int dem = 0, x = 0, y = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
    {
        char t;
        cin >> t;
        if (t == 'U')
            y++;
        if (t == 'D')
            y --;
        if (t == 'L')
            x--;
        if (t == 'R')
            x++;
        if (x == y && y == 0)
            dem = i;
    }
    cout << dem;
	return 0;
}
