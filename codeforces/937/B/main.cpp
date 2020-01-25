#include <bits/stdc++.h>

using namespace std;

int p, k;

int main()
{
    cin >> p >> k;
    for (int i = k; i > p; i--)
    {
        bool check = true;
        int t = sqrt(i);
        for (int j = 2; j <= min(t, p); j++)
            if (i%j == 0 || (i%j == 0 && i/j <= p))
        {
            check = false;
            break;
        }
        if (check)
            return cout << i, 0;
    }
    cout << -1;
    return 0;
}
