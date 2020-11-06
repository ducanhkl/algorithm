#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n;
int a[maxn];
/*
int check(int idx, int r)
{
    for (int i = idx+1; i <= r; i++)
        if (a[i] > r)
            return false;
    return true;
}

void solve()
{
    sort(a+1, a+n+1);
    for (int i = 0; i <= n; i++)
    {
        int l = i+1, r = n;
        int res = -1;
        while (l <= r)
        {
            int mid = (l+r)/2;
            if (check(i, mid))
                res = mid, l = mid+1;
            else
                r = mid-1;
        }
        if (res == -1)
        {
            cout << i+1 << endl;
            return;
        }
        i = res-1;
    }
    cout << n+1 << endl;
}*/

void solve()
{
    sort(a+1, a+n+1);
    int i;
    for (i = 0; i <= n; i++)
    {
        int res = -1;
        for (int j = i+1; j <= n; j++)
            if (a[j] <= j)
                res = j;
        if (res == -1)
            break;
        i = res-1;
    }
    cout << i+1 << endl;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        solve();
    }
    return 0;
}
