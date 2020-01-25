#include <bits/stdc++.h>
#define maxn 2*100006

using namespace std;


int a[maxn];
int n, m = INT_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], m = min(m, a[i]);
    int pos = 1;
    pos = pos + (m%n);
    for (int i = 1; i <= n; i++)
        a[i] -= m;
    for (int i = 1; i <= n; i++)
        a[n+i] = a[i];
    for (int i = pos; i <= 2*n; i++)
        if (i-pos >= a[i])
    {
        if (i <= n)
            cout << i;
        else
            cout << i-n;
        return 0;
    }
    return 0;
}
