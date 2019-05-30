#include <bits/stdc++.h>
#define maxn 100004

using namespace std;

long long ans = 0, a[2*maxn];
int n, s, f, vt;
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[n+i] = a[i];
    n *= 2;
    for (int i = 1; i <= n; i++)
        a[i] += a[i-1];
    cin >> s >> f;
    int k = f-s;
    n /= 2;
    for (int i = 0; i < n; i++)
    {
        if (a[k+i] - a[i] > ans)
        {
            ans = a[k+i]-a[i];
            vt = (n+s-i-1)%n+1;
        }
        if (a[k+i] - a[i] == ans)
            vt = min(vt, (n+s-i-1)%n+1);
    }
    cout << vt;
    return 0;
}
