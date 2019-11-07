#include <bits/stdc++.h>

using namespace std;

int ma = -maxc, mi = maxc;
int n, l, r, k;

int main()
{
    cin >> n;
    for >> l >> r >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    b[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] > a[i-1])
        {
            b[i] = b[i-1] + 1;
        }
        if (a[i] < a[i-1])
        {
            b[i] = b[i-1] + 1;
        }
        if (a[i] == a[i-1])
        {
            b[i] = b[i-1];
        }
        ma = max(ma, b[i]);
        mi = min(mi, b[i]);
    }
    if (ma - mi > r - l)
    {
        cout << -1;
        return ;
    }
    for (int i = 1; i <= n; i++)
    {
        b[i] = b[i] - mi + l;
    }
    b[0] = maxc, b[n+1] = maxc;
    for (int i = 2; i < n; i++)
    {
        if (b[i] < b[i-1] && b[i] < b[i+1])
        {
            b[i] = l;
            for(int j = i-1; j >= 1 && b[j] < b[j-1]; j--)
                b[j] = b[j+1] + 1;
            for(int j = i+1; j <= n && b[j] < b[j-1]; j--)
                b[j] = b[j+1] + 1;
        }
    }
    for (int i = 1; i <= n; i++)
        cout << b[i]  << " ";
    return 0;
}
