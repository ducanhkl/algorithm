#include <bits/stdc++.h>

using namespace std;

long long calc(long long  n, long long k)
{
    long long p = 2LL<<n-1;
    if (k > (p+1)/2)
        return calc(n-1, k-(p+1)/2);
    if (k < (p+1)/2)
        return calc(n-1, k);
    if (k == (p+1)/2)
        return n;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    int t;
    long long n, k;
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cout << calc(n, k) << endl;
    }
    return 0;
}
