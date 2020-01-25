#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789

using namespace std;

int a[10];
long long t = 0;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	for (int i = 1; i <= 6; i++)
        cin >> a[i], t += a[i];
    for (int i = 1; i <= 4; i++)
        for (int j = i+1;j <= 5; j++)
            for (int k = j+1; k <= 6; k++)
                if (a[i] + a[j] + a[k] == t/2 && t%2 == 0)
                    return cout << "YES", 0;
    cout << "NO";
	return 0;
}
