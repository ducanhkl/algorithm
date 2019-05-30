#include <bits/stdc++.h>
#define maxc 123456789123499
#define maxn 5000

using namespace std;

long long dd1[maxn], dd2[maxn], s[maxn], c[maxn];
long long ans = maxc;
int n;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < maxn; i++)
        dd1[i] = dd2[i] = maxc;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (s[i] > s[j])
                dd1[i] = min(dd1[i], c[i]+c[j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (s[i] > s[j])
                dd2[i] = min(dd2[i], c[i] + dd1[j]);
    for (int i = 1; i <= n; i++)
        ans = min(ans, dd2[i]);
    if (ans == maxc)
        cout << -1;
    else cout << ans;
    return 0;
}
