#include <bits/stdc++.h>

using namespace std;

long long a, b, m[4];
int t;

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> t;
    while (t--)
    {
        int dem = 0;
        cin >> a >> b;
        m[0] = m[1] = m[2] = b;
        while (m[2] < a)
        {
            m[0] = m[1] + m[2] - 1;
            sort(m, m+3);
            dem ++;
        }
        cout << dem + 2 << endl;
    }
    return 0;
}
