#include <bits/stdc++.h>

using namespace std;

long long a , b, res, ans;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        cin >> a >> b;
        res = abs(a-b);
        ans = res/5;
        res = res%5;
        ans += res/2;
        res = res%2;
        ans += res;
        cout << ans << endl;
    }
}
