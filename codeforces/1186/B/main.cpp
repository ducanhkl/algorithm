#include <bits/stdc++.h>

using namespace std;

long long n, m;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    if (n > m)
        swap(n, m);
    long long res1 = (n/3)*(m/2+(m%2))+ (n%3 == 1)*(m/3) + (n%3 == 2)*(m/2);
    long long res2 = (n/2)*(m/3)+((m%3) > 0)*(n/3);
    cout << max(res1, res2);
    return 0;
}
