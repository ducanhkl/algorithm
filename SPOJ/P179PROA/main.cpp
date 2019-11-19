#include <bits/stdc++.h>
#define ll long long
#define pii pair <long long, long long>
#define mp make_pair
#define maxn 1000005 // gap n tu dinh nghia la 1000005

using namespace std;

long long k[maxn], m[maxn], r[maxn];
string p[maxn], res;
long long ans = 0;
int n;

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(r, 0, sizeof(r));
    //ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> p[i] >> k[i] >> m[i];
    for (int i = 1; i <= n; i++)
        while (m[i] >= k[i])
            r[i] += m[i]/k[i], m[i] = m[i]%k[i] + (m[i]/k[i])*2;
    for (int i = 1; i <= n; i++)
        ans += r[i];
    cout << ans << endl;
    ans = -1;
    for (int i = 1; i <= n; i++)
        if (r[i] > ans)
            ans = r[i], res = p[i];
    cout << res;
    return 0;
}
