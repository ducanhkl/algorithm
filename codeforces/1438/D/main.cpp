#include <bits/stdc++.h>

using namespace std;

int main()
{
    int res = 0;
    int n;
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i =1 ; i <= n; i++)
    {
        int x;
        cin >> x;
        res ^= x;
    }
    if (n%2 == 0)
    {
        if (res == 0)
        {
            n--;
        } else
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES" << endl;
    cout << n-1 << endl;
    for (int i = 1; i < n; i += 2)
    {
        cout << i << " " << i+1 << " " << i+2 << endl;
    }
    for (int i = 1; i < n;  i += 2)
    {
        cout << i << " " << i+1 << " " << n << endl;
    }
    return 0;
}
