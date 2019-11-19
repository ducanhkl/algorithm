#include <bits/stdc++.h>

using namespace std;

long long n, m, k;

bool check_prime(int x)
{
    if (x == 0 || x == 1)
        return false;
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return false;
    return true;
}
long long calc(long long x, long long y)
{
    if (x < y)
        return 0;
    if (!check_prime(y))
        return 0;
    long long ans = x/y;
    x /= y;
    for (int i = 2; i < y; i++)
        ans -= calc(x, i);
    return ans;
}
int main()
{
    cin >> n >> m >> k;
    cout << calc(m, k) - calc(n-1, k);
    return 0;
}
