#include <bits/stdc++.h>

using namespace std;

int n, k;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    if (k == 1 || k == n)
        return cout << n*3, 0;
    cout << min(n-k+1, k)*3-2+(max(n-k+1, k)-1)*2+n+1;
    return 0;
}
