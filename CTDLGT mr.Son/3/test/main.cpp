#include <bits/stdc++.h>

using namespace std;

int n;
const long long mod = 1e15+7;
long long a[1000010];

int main()
{
    freopen("out.txt", "w", stdout);
    cin >> n;
    a[1] = 1, a[2] = 2, a[3] = 3;
    for (int i = 4; i <= n; i++)
        a[i] = (a[i-1] + a[i-2] + a[i-3])%mod;
    for (int i = 1; i <= n; i++)
        a[i] = (a[i-1] + a[i])%mod;
    for (int i = 1; i <= n; i++)
        cout << i << " " << a[i] << endl;
    return 0;
}
