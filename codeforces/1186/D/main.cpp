#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
int n;
long double a[maxn], b[maxn], sum = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        b[i] = floor(a[i]), sum += b[i];
    for (int i = 1; i <= n && sum != 0; i++)
        if (b[i] != ceil(a[i]))
    {
        b[i] = ceil(a[i]);
        sum ++;
    }
    for (int i = 1; i <= n; i++)
        cout << (int)(b[i]) << endl;
    return 0;
}

