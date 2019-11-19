#include <bits/stdc++.h>

using namespace std;

long long n, x;

int main()
{
    cin >> n >> x;
    for (int i = 1; i <= 2*n; i++)
    {
        if (x % 2 == 0)
        {
            x = x/2;
            x += 1<<(n-1);
        } else
        {
            x--;
            x/=2;
        }
        cout << bitset <6> (x) << endl;
    }
    return 0;
}
