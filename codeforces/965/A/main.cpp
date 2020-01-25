#include <bits/stdc++.h>

using namespace std;

long long k, n, s, p;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> k >> n >> s >> p;
    int t = ceil(k*n*1.0/s);
    int v = ceil(t*1.0/k);
    cout << (long long)ceil(v*k*1.0/p);
    return 0;
}
