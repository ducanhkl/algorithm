#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 2)
        {
            cout << 2 << endl;
        } else
        cout << max((n-4)%2, 0) << endl;
    }
    return 0;
}
