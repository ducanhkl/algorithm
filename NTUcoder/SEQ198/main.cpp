#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<long long, long long>
#define priority_queue pq
#define ll long long
#define maxnum 123456789
#define maxn 2006

using namespace std;

map <int, long long> s;
int a[maxn], b[maxn], n, f[maxn][maxn];
int ans = -1;
int main()
{
    //freopen("inp.txt", "r", stdin);
	ios_base::sync_with_stdio(0), cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++)
        cin >> a[i], s[a[i]]++;
    int m = n; n = 0;
    memset(f, 0, sizeof(f));
    for (map <int, long long>::iterator i = s.begin(); i != s.end(); i++)
    {
        n++;
        a[n] = i->first;
        b[n] = i->second;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 1024; j++)
        {
            if ((j&1) == 0)
                f[i][j] = max(f[i-1][(j>>1)], f[i-1][(j>>1) ^ (1<<9)]);
            else
            {
                bool isSEQ198 = true;
                for (int k = 1; k < 10; k++)
                    if (j & (1<<k))
                        if (a[i] - a[i-k] == 1 || a[i] - a[i-k] == 8 || a[i] - a[i-k] ==9)
                {
                    isSEQ198 = false;
                    break;
                }
                if (isSEQ198)
                    f[i][j] = max(f[i-1][j>>1], f[i-1][j>>1 ^ (1<<9)]) + b[i];
            }
            ans = max(ans, f[i][j]);
        }
    cout << m - ans;
    return 0;
}
