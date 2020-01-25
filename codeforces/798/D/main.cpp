#include <bits/stdc++.h>

using namespace std;

int n;
struct data
{
    int a, b, pos;
} a[1000005];

bool cmp(data x, data y)
{
    return x.a > y.a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].a;
    for (int i = 1; i <= n; i++)
        cin >> a[i].b;
    for (int i = 1; i <= n; i++)
        a[i].pos = i;
    sort(a+1, a+n+1, cmp);
    cout << n/2+1 << endl << a[1].pos << " ";
    for (int i = 2; i <= n; i += 2)
        if (a[i].b > a[i+1].b)
            cout << a[i].pos << " ";
        else cout << a[i+1].pos << " ";
    return 0;
}
