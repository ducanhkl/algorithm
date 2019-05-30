#include <bits/stdc++.h>

using namespace std;

long long w1, h1, w2, h2, ans = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w1 >> h1 >> w2 >> h2;
    ans = w1 + h1 + w2 + h2;
    ans *= 2;
    ans += 8;
    ans -= 2*min(w1, w2) + 4;
    cout << ans;
    return 0;
}
