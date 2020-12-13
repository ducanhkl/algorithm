#include <bits/stdc++.h>

using namespace std;


const int maxn = 600;

int n, x;
int a[maxn];
int ans = 0;

bool check()
{
    for (int i = 1; i < n; i++)
    {
        if (a[i] > a[i+1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test --)
    {
        ans = 0;
        cin >> n >> x;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            if (check())
            {
                break;
            }
            if (a[i] > x)
            {
                ans ++;
                swap(a[i], x);
            }
        }
        if (check())
        {
            cout << ans;
        } else
        {
            cout << -1;
        }
        cout << endl;
    }
    return 0;
}
