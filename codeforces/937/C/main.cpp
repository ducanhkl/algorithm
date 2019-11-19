#include <bits/stdc++.h>

using namespace std;

long long k, d, t;

int main()
{
    ios_base::sync_with_stdio(false);
	cin >> k >> d >> t;
	if (k % d == 0)
        return cout << t, 0;
	long long x, y;
	if (k < d)
		x = k, y = d-k;
	else x = k, y = d-(k%d);
	long long s = x+y;
	long double _l1 = (long double)x / t;
	long double _l2 = (long double)y / (2*t);
	long double _l = (long double)x / t + (long double)y / (2*t);
	long long sky = 1/_l;
	double sum = s*sky;
	double du = 1-_l*sky;
	if (du <= _l1) {
		sum += du/_l1*x;
	}
	else {
		sum += x + (du-_l1)/_l2*y;
	}
	cout << fixed << setprecision(9) << sum;
	return 0;
}
