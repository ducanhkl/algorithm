#include <bits/stdc++.h>

using namespace std;

long long n, a, b, s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> a >> b >> s;
    if (s - a*n < 0 || a*n > b)
        cout << "NO";
    else
        cout << "YES";
    return 0;
}
