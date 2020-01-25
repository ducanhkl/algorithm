#include <bits/stdc++.h>

using namespace std;

void Remove(int *a, int &n, int x)
{
    int l = -1, r = -1;
    for (int i = 0; i < n; i++)
        if (a[i] == x)
            if (l == -1)
                l = i, r = i;
            else r = i;
    if (l != -1)
        n -= r-l+1;
    else return;
    for (int i = l; i <= r; i++)
        a[i] = a[r+i-l+1];
}
int main()
{
    int n, a[10000], x;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> x;
    Remove(a, n, x);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}
