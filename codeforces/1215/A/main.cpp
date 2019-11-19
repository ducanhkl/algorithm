#include <bits/stdc++.h>

using namespace std;

long long a1, a2, k1, k2, n, ansMa = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a1 >> a2;
    cin >> k1 >> k2;
    if (k1 > k2)
    {
        swap(k1, k2);
        swap(a1, a2);
    }
    cin >> n;
    long long cnt = n/k1;
    if (cnt > a1)
        {
            cnt = a1 + (n-a1*k1)/k2;
        }

    cout << max(n - ((k1-1)*a1 + (k2-1)*a2), 0LL) << " " << cnt;
    return 0;
}
