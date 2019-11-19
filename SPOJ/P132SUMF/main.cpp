#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 1000006
#define reset(a) memset(a, 0, sizeof(a))

using namespace std;

struct data
{
    int r1;
    int r2;
    int r3;
};

data a[maxn];
int n, dd1[maxn], dd2[maxn], mark[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    reset(dd1);
    reset(dd2);
    reset(mark);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
        cin >> a[i].r1;
    for (int i = 1; i <= n; i++)
        cin >> a[i].r2;
    for (int i = 1; i <= n; i++)
        cin >> a[i].r3;
    for (int i = 1; i <= n; i++)
        dd1[a[i].r2] ++, dd2[a[i].r3] ++;
    bool dd = true;
    int ans = 0;
    while (dd)
    {
        dd = false;
        int r = 0;
        for (int i = 1; i <= n; i++)
            if (!mark[i] && (!dd1[a[i].r1] || !dd2[a[i].r1]))
        {
            mark[i] = 1;
            r ++;
            dd = true;
            if (dd1[a[i].r2] > 0)
                dd1[a[i].r2] --;
            if (dd2[a[i].r3] > 0)
                dd2[a[i].r3] --;
        }
        ans += r;
    }
    cout << ans;
	return 0;
}
