#include <bits/stdc++.h>

using namespace std;

int w, h, w1, d1, w2, d2;

int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w >> h >> w1 >> d1 >> w2 >> d2;
    for (int i = h; i >= 0; i--)
    {
        w += i;
        if (i == d1)
        {
            w -= w1;
            w = max(w, 0);
        }
        if (i == d2)
        {
            w -= w2;
            w = max(w, 0);
        }
    }
    cout << w;
    return 0;
}
