#include <bits/stdc++.h>

using namespace std;

long long k, a, b;

int main()
{
    cin >> k >> a >> b;
    k -= a;
    if (a > b)
        return cout << k+a+1, 0;
    long long cnt = (k+1)/2;
    if (k%2)
        cout << max(cnt*b-(cnt-1)*a, k+a+1);
    else
        cout << max(cnt*b-(cnt-1)*a, k+a)+1;
    return 0;
}
