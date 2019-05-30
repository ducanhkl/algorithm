#include <bits/stdc++.h>

using namespace std;

int a, b;
int ans = INT_MAX;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b;
    if (a > b)
        swap(a, b);
    for (int i = a; i <= b; i++)
    {
        int d1 = i-a;
        d1 = (d1*(d1+1))/2;
        int d2 = b-i;
        d2 = (d2*(d2+1))/2;
        ans = min(ans, d1+d2);
    }
    cout << ans;
    return 0;
}
