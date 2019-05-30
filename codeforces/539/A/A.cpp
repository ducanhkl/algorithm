#include <bits/stdc++.h>

using namespace std;

int n, k, d = 0;
int a[101];
int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i<= n; i++)
    {
        cin >> a[i];
        if (a[i-1] > 8)
            a[i] += a[i-1] - 8;
        d += min(8, a[i]);
        if (d >= k)
        {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
