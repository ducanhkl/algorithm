#include <bits/stdc++.h>

using namespace std;

long long a, b, c, n;

int main()
{
    cin >> a >> b >> c >> n;
    int sl = a + b - c;
    if (sl >= n || a >= n || b >= n || c >= n || c > a || c > b)
        cout << -1;
    else cout << n - sl;
    return 0;
}
