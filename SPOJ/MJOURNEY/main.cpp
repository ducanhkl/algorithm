#include <bits/stdc++.h>
#define maxn 2000

using namespace std;

pair <long long, int> p[maxn], w[maxn];
long long ans[maxn], d[maxn], t, n;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> t;
    for (int i= 1; i <= n; i++)
        cin >> w[i].first, w[i].second = i;
    for (int i = 1; i <= n; i++)
        cin >> d[i];
    for (int i = 1; i <= n; i++)
        cin >> p[i].first, p[i].first -= d[i]*t, p[i].second = i;
    sort (p+1, p+n+1);
    sort (w+1, w+n+1);
    for (int i = 1; i <= n; i++)
        ans[p[i].second] = w[i].second;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
    return 0;
}
