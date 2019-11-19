#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000006

using namespace std;

int n, a[maxn], s[maxn], b[maxn], x, k;

void init()
{
    memset(a, 0, sizeof(a));
    memset(s, 0, sizeof(s));
    memset(b, 0, sizeof(b));
    for (int i = 2; i <= 1000; i ++)
        if (!a[i])
            for (int j = 2*i; j <= 1000; j += i) a[j] = 1;
    int t = 0;
    for (int i = 2; i <= 1000; i ++)
        if (!a[i])
            s[++t] = i;
    for (int i = 1; i < t; i ++)
        b[s[i] + s[i+1]] = true;
}
int main()
{
    freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	init();
	while(n--)
    {
        int dem = 0;
        cin >> x >> k;
        for (int i = 2; i <= x; i++)
            if (a[i] == 1 && b[i-1])
                dem ++;
        if (dem >= k)
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }
	return 0;
}
