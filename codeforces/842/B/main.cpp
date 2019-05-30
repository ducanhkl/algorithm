#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

double r, d, dem = 0;
int n;

int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> r >> d;
    cin >> n;
    while (n --)
    {
        double x, y, ri;
        cin >> x >> y >> ri;
        double kc = sqrt(x*x+y*y);
        if (kc + ri <= r && kc - ri >= r-d)
            dem ++;
    }
    cout << dem;
    return 0;
}
