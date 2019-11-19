#include <bits/stdc++.h>
#define maxn 20

using namespace std;

int n;
long long p[20], dd[20], a[20];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int n = 0;
    int t;
    while (cin >> t)
    {
        a[++n] = t;
    }
    int k = a[n--];
    long long ans = 0;
    p[1] = p[0] = 1;
    for (int i = 2; i <= 15; i++)
        p[i] = i*p[i-1];
    memset(dd, 0, sizeof(dd));
    for (int i = 1; i <= n; i++)
    {
        int dem = 0;
        for (int j = 1; j <= a[i]; j++)
            if (dd[j] == 0)
                dem ++;
        dd[a[i]] = 1;
        ans += (dem-1)*p[n-i];
    }
    cout << ans+1 << endl;
    memset(dd, 0, sizeof(dd));
    for (int i = 1; i <= n; i++)
    {
        int jj, dem = 0;
        for (int j = 1; j <= n; j++)
        {
            if (dd[j] == 0)
                dem ++, jj = j;
            if (dem*p[n-i] >= k)
                break;
        }
        a[i] = jj;
        dd[jj] = 1;
        k -= (dem-1)*p[n-i];
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    return 0;
}
