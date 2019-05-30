#include <bits/stdc++.h>
#define maxn 300000

using namespace std;

long long ans, n, l[maxn], r[maxn], a[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    ans = n*(n-1)/2;
    for (int i = 1; i <= n; i++)
        cin >> a[i], l[i] = r[i] = i;
    for (int i = 2; i <= n; i++)
    {
        int t = i;
        while (t > 1 && (a[i]|a[t-1]) == a[i])
            t = l[t-1];
        l[i] = t;
    }
    for (int i = n-1; i >= 1; i--)
    {
        int t = i;
        while (t < n && (a[i]|a[t+1]) == a[i] && a[i] != a[t+1])
            t = r[t+1];
        r[i] = t;
    }
    for (int i = 1; i <= n; i++)
        ans -= (i-l[i])*(r[i]-i)+r[i]-l[i];
    cout << ans;
}
