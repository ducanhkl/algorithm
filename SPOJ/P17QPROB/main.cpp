#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000004

using namespace std;

int n;
string a[maxn];

bool cmp(string a, string b)
{
    return (a+b < b+a);
}
int main()
{
    int t;
    freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> t;
	while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a+1, a+n+1, cmp);
        for (int i = 1; i <= n; i++)
            cout << a [i];
        cout << endl;
    }
	return 0;
}
