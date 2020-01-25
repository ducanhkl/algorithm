#include <bits/stdc++.h>

using namespace std;

int a, b, c, d;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> c >> d;
    if (abs(c-d) > 1 || a < c || a < d || b < c || d < d)
        return cout << "Yeu Ha Noi", 0;
    if (c > d)
    {
        a -= c;
        b -= c;
        for (int i = 1; i <= a; i++)
            cout << 2;
        for (int i = 1; i <= c; i++)
            cout << 28;
        for (int i = 1; i <= b; i++)
            cout << 8;
        return 0;
    }
    if (c < d)
    {
        a -= d-1;
        b -= d-1;
        cout << 8;
        for (int i = 1; i <= a; i++)
            cout << 2;
        for (int i = 1; i < d-1; i++)
            cout << 82;
        for (int i = 1; i <= b; i++)
            cout << 8;
        cout << 2;
        return 0;
    }
    if (c == d)
    {
        if (min(a, b ) > c)
        {
            for (int  i = 1; i <= a-c-1; i++)
                cout << 2;
            for (int i = 1; i <= c; i++)
                cout << 28;
            for (int i = 1; i <= b-c; i++)
                cout << 8;
        } else
            if (min(a, b) == c)
            {
                if (a != b)
                {
                    if (a > b)
                        for (int i = 1; i <= a-c; i++)
                            cout << 2;
                    for (int i = 1; i <= c; i++)
                        cout << 82;
                    if (a < b)
                        for (int i = 1; i <= b-c; i++)
                        cout << 8;
                } else
                {
                    //cout << "Yeu Ha Noi";
                }
            }
    }
    return 0;
}
