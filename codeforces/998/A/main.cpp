#include <bits/stdc++.h>

using namespace std;

long long n, a[20];
long long tong = 0;
long long dd[20];


int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(a, 0, sizeof(a));
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], tong += a[i];
    for (int b = 1; b < 1<<n; b++)
    {
        int t = 0, dem = 0;
        memset(dd, 0, sizeof(dd));
        for (int i = 1; i <= n; i++)
            dd[i] = (b >> (i-1) & 1);
        for (int i = 1; i <= n; i++)
            if (dd[i] == 1)
                t += a[i], dem ++;
        /*for (int i = 1; i <= n; i++)
            cout << dd[i] << " ";*/
        //cout << endl;
        if (t != tong-t && t != tong)
        {
            cout << dem << endl;
            for (int i = 1; i <= n; i++)
                if (dd[i])
                    cout << i << " ";
            return 0;
        }
    }
    cout << -1;
    return 0;
}
