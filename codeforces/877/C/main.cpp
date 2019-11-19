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
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	cout << n + n/2 << endl;
	for (int i = 2; i <= n; i+= 2)
        cout << i <<  " ";
    for (int i = 1; i <= n; i+= 2)
        cout << i <<  " ";
    for (int i = 2; i <= n; i+= 2)
        cout << i << " ";
	return 0;
}
