#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000006
using namespace std;

int n, a[maxn+1];
int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        a[x] ++;
    }
    cout << max_element(a+1, a+maxn) - a;
	return 0;
}
