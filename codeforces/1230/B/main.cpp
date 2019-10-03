#include <bits/stdc++.h>

using namespace std;

const int maxn = 100;
int a[maxn], p[maxn];
int n, k;

int main()
{
    memset(p, 0, sizeof(p));
    cin >> n >> k;
    if (n == 1 && k > 0)
    {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        char x;
        cin >> x;
        a[i] = x-'0';
    }
    p[1] = 1;
    int pos = 1;
    while (pos <= n && k != 0)
    {
        if (a[pos] != p[pos])
            k--, a[pos] = p[pos];
        pos ++;
    }
    for (int i = 1; i <= n; i++)
        cout << a[i];
    return 0;
}
