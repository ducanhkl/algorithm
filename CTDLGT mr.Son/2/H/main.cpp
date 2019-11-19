#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int t;
int n, a[maxn], dd[maxn ];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sort(a+1, a+n+1);
        memset(dd, 0, sizeof(dd));
        int l = n/2, ans = 0;
        for (int i = n; i >= 1; i--)
        {
            while (a[l] > a[i]/2 && l >= 1)
                l--;
            while (dd[l] == 1 && l >= 1)
                l--;
            if (l < 1)
                    break;
            if (dd[l] == 0 && a[l] <= a[i]/2)
                dd[l] = dd[i] = 1, ans++;
        }
        cout << n-ans << endl;
    }
    return 0;
}
