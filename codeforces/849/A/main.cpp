#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000006
using namespace std;

int n, a[maxn];
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (n%2 != 0 && a[1]%2 == 1 && a[n]%2 == 1)
        cout << "Yes";
    else cout << "No";
	return 0;
}
