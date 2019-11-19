#include <bits/stdc++.h>

using namespace std;

long long n;

int main()
{
    ios_base::sync_with_stdio(false);
    // k^2 +(2k+1) = (k+1)^2;
    // (k-1)^2 + 4*k = (k+1)*(k+1);
    cin >> n;
    if (n == 1 || n == 2)
    {
        cout << -1;
        return 0;
    }
    if (n%2)
    {
        long long k = (n*n-1)/2;
        cout << k << " " << (k+1);
    } else
    {
        long long k = n*n / 4;
        cout << (k-1) << " " << (k+1);
    }
    return 0;
}
