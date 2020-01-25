#include <bits/stdc++.h>

using namespace std;

int a[10], p[10];

int main()
{
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    for (int i = 1; i < 16; i++)
    {
        int ans1 = 0, ans2 = 0;
        for (int j = 0; j < 4; j++)
            p[j] = (i>>j)&1;
        for (int j = 0; j < 4; j++)
        {
            if (p[j] == 1)
                ans1 += a[j];
            else
                ans2 += a[j];
        }
        if (ans1 == ans2)
        {
            cout << "YES"
            ;
            return 0;
        }
    }
    cout << "NO";
    return 0;
}
