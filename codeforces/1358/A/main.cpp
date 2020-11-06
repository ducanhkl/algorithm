#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("inp.txt", "r", stdin);
    int test, n, m;
    cin >> test;
    while (test--)
    {
        cin >> n >> m;
        int ans = (n/2)*m;
        if (n%2)
            ans += m/2+(m%2 == 1);
        cout << ans << endl;
    }
    return 0;
}
