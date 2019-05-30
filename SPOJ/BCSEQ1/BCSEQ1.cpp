#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 100004
using namespace std;

vector <int> v;
int n, a[maxn], t;

void make_divisor(ll k)
{
    if (sqrt(k)*sqrt(k) == k)
        v.push_back(sqrt(k));
    for (int i = 1; i < sqrt(k); i++)
        if (k%i == 0)
            v.push_back(i), v.push_back(k/i);
    return;
}
int main()
{
    freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	memset(a, 0, sizeof(a));
	cin >> t;
	while (t--)
    {
        int n, x;
        cin >> x >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i], a[i] += a[i-1];
        make_divisor(a[n]);
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            int l = 0, check = 1;
            for (int j = 1; j <= n; j++)
            {
                if (a[j] - a[l] > v[i])
                {
                    check = false;
                    break;
                }
                if (a[j] - a[l] == v[i])
                    l = j;
            }
            if (check)
            {
                cout << x << " " << v[i] << endl;
                break;
            }
        }
        v.clear();
        memset(a, 0, sizeof(a));
    }
	return 0;
}
