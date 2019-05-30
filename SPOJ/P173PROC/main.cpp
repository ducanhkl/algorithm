#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000005

using namespace std;

int a[maxn], dem[maxn];
int n, k;

int main()
{
    int t;
    //freopen("inp.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> t;
	while (t--)
    {
        cin >> n >> k;
        memset(a, 0, sizeof(a));
        memset(dem, 0, sizeof(dem));
        if (k == 0)
        {
            for (int i = 1; i <= n; i++)
                cout << i << " ";
            cout << endl;
            continue;
        }
        int ma = 0;
        for (int i = 1;i <= n; i++)
            if (a[i] == 0)
                a[i] = i+k, a[i+k] = i, dem[i] ++, dem[i+k]++, ma = max(ma, i+k);
        bool check = true;
        for (int i = 1; i <= n; i++)
            if (abs(a[i]-i) != k || dem[i] != 1 | ma > n)
                check = false;
        if (check)
            for (int i = 1; i <= n; i++)
                cout << a[i] << " ";
        else cout << -1;
        cout <<endl;
    }
	return 0;
}
