#include <bits/stdc++.h>

using namespace std;

long long n, k, a, b;
long long ans = 0;

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> n >> k >> a >> b;
    if (k == 1)
        return cout << (n-1)*a, 0;
    while (n > 1)
    {
        ans += (n%k)*a;
        n -= (n%k);
        if ((n-n/k)*a >= b)
            n /= k, ans+=b;
        else{
            ans += (n-1)*a;
            break;
        }
    }
    cout << ans;
    return 0;

}
