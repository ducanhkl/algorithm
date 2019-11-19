#include <bits/stdc++.h>

using namespace std;

int dd[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
long long ans, n;

int main()
{
    int t;
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        cin >> n;
        ans = 0;
        for (int i = 9; i >= 0; i--)
        {
            ans += n/dd[i];
            n = n%dd[i];
        }
        cout << ans << endl;
    }
    return 0;
}
