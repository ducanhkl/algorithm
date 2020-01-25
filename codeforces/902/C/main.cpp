#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 100004

using namespace std;

int a[maxn];
int n;

int main()
{
    int check = 0;
    freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n+1; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        if (a[i] >= 2 && a[i+1] >= 2)
            check = i+1;
    if (check == 0)
        return cout << "perfect", 0;
    cout << "ambiguous" << endl;
    for (int i = 1; i <= n+1; i++)
    {
        a[i] += a[i-1];
        for (int j = a[i-1]; j < a[i]; j++)
            cout << a[i-1] << " ";
    }
    cout << endl;
    for (int i = 1; i <= n+1; i++)
    {
        for (int j = a[i-1]; j < a[i] - (check == i); j++)
            cout << a[i-1] << " ";
        if (check == i)
            cout << a[i-1] - 1 << " ";
    }
	return 0;
}
