#include <bits/stdc++.h>
#define maxn 1001
#define maxc 1e9+7

using namespace std;

int a[maxn], n, d[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i ++)
        {
            char x;
            cin >> x;
            a[i] = (int)x - (int)'0';
        }
    d[0] = 1;
    for (int i = 1; i<= n; i++)
        d[i] = d[i-1]*2;
    int s = 1;
    for (int i = 1; i<= n+1; i++)
        if (a[n-i+1] == 1)
            s += d[i-1];
    cout << s;
    return 0;
}
