#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 10004

using namespace std;

char a[maxn][maxn];
int l[maxn], r[maxn], n, m, t[maxn];
ll ans = -maxnum;

int main()
{
    freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
        {
            l[i] = m+1;
            for (int j = 0; j < m+2; j++)
                {
                    cin >> a[i][j];
                    if (a[i][j]=='1')
                        l[i] = min(j, l[i]), r[i] = max(j, r[i]), t[i] = 1;
                }
        }
    int l1 = 0, r1 = 0;
    for (int i = n; i >= 1; i --)
    {
        if (t[i] == 0)
        {
            l1 ++, r1 ++;
            continue;
        }
        int l2 = min(r1+m+2, l1 +  2*r[i]+1);
        int r2 = min(r1+2*(m+1-l[i])+1, l1 + m + 2);
        ans=min(l1+r[i],r1+m+1-l[i]);
        l1 = l2;
        r1 = r2;
    }
    cout << ans;
	return 0;
}
