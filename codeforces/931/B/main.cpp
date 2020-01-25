#include <bits/stdc++.h>

using namespace std;
int x, y,n, v = 0;
int a[300], b[300];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> x >> y;
    if (x > y)
        swap(x, y);
    for (int i = 1; i <= n; i++)
        a[i] = i;
    while (n > 2)
    {
        v++;
        int dem = 0;
        memset(b, 0, sizeof(b));
        for (int i = 1; i < n; i+=2)
            if (a[i] != x && a[i+1] != y && a[i] != y && a[i+1] != x )
                b[++dem] = a[i];
            else {
                if ((a[i] == x && a[i+1] == y ) || (a[i] == y && a[i+1] == x))
                    return cout << v, 0;
                if (a[i] == x || a[i+1] == x)
                {
                    b[++dem] = x;
                } else b[++dem] = y;
            }
        n = dem;
        memset(a, 0, sizeof(a));
        for (int i = 1; i <= dem; i++) a[i] = b[i];
    }
    cout << "Final!";
    return 0;
}
