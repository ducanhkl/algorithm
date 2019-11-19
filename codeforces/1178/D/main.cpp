#include <bits/stdc++.h>

using namespace std;

int n;

bool prime(int x)
{
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    if (n == 3)
    {
        cout << 3 << endl;
        cout << 1 << " " << 2 << endl << 2 << " " << 3 << endl << 3 << " " << 1;
        return 0;
    }
    for (int i = n; i <= 3*n/2; i++)
        if (prime(i))
    {
        cout << i << endl;
        for (int j = 1; j <= n; j++)
        {
            cout << j << " ";
            if (j == n)
                cout << 1;
            else
                cout << j+1;
            cout << endl;
        }
        for (int j = 1; j <= i-n; j++)
            cout << j << " " << j+(n/2) << endl;
        return 0;
    }
    return 0;
}
