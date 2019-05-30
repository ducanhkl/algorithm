#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

struct data
{
    double x, y;
};

data a, b, c;

double d(data n, data m)
{
    return sqrt((n.x - m.x)*(n.x - m.x) + (n.y-m.y)*(n.y-m.y));
}
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	//cout << d(a, b) << " " << d(b, c) << " ";
	if (d(a, b) == d(b, c))
        if ((a.x+c.x)/(double)2 != b.x || (a.y+c.y)/2 != b.y)
        cout << "YES";
        else cout << "No";
    else cout << "No";
	return 0;
}
