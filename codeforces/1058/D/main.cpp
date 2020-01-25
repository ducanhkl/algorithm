#include <bits/stdc++.h>

using namespace std;

long long n, m, k, g, a, b;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    if (2*m*n%k != 0)
        return cout << "NO", 0;
    cout << "YES" << endl;
    if (k%2 == 0)
    {
        k /= 2;
        g = __gcd(k, n);
        cout << "0 0 \n" << "0 " << m*g/k << "\n" << n/g << " 0";
        return 0;
    }
    g = __gcd(k ,n);
    a = n/g;
    b = m*g/k;
    if (a < n)
        a *= 2;
    else
        b *= 2;
    cout << "0 0\n" << "0 " << b << "\n" << a << " 0";
    return 0;
}
