#include <bits/stdc++.h>

using namespace std;

unsigned long long f[100];
int n;
long long k;

void init()
{
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= 92; i++)
        f[i] = f[i-1]+f[i-2];
}

char calc(int x, long long k)
{
    if (x == 1)
        return 'A';
    if (x == 2)
        return 'B';
    if (k <= f[x-2])
        return calc(x-2, k);
    if (k > f[x-2])
        return calc(x-1, k-f[x-2]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    init();
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cout << calc(n, k) << endl;
    }
    return 0;
}
