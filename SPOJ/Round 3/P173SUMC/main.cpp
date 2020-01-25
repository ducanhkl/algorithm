#include <bits/stdc++.h>

using namespace std;
int n, m, r;
int dem = 0;
int main()
{
    cin >> n >> m;
    r = abs(n - m);
    for (int i = 1; i <= sqrt(r); i ++)
        if (r%i == 0)
            if (((r/i + i)+1)%2 == 0)
                dem ++;
    cout << dem;
    return 0;
}
