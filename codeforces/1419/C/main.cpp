#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3+100;

int n;
long long a[maxn];
long long x;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n >> x;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int ck = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] != x)
                ck = 1;
        if (ck == 0)
        {
            cout << 0 << endl;
            continue;
        }
        ck = 0;
        for (int i = 1; i <= n; i++)
            if (a[i] == x)
            {
                ck = 1;
                break;
            }
        if (ck == 1)
        {
            cout << 1 << endl;
            continue;
        }
        long long ans = 0;
        for (int i = 1; i < n; i++)
            ans += a[i] - x;
        if (a[n] + ans == x)
            cout << 1;
        else
            cout << 2;
        cout << endl;
    }
    return 0;
}
