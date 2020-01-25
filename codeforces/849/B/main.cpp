#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000006

using namespace std;

double n, a[maxn];

double check(double y)
{
    set <double> t;
    for (int i = 1; i <= n; i++)
        t.insert(a[i] - y*(double)i);
    return t.size() == 2;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (check(a[2] - a[1]) || check(a[3] - a[2]) || check((a[3] - a[1])/2))
        cout << "Yes";
    else cout << "No";
	return 0;
}
