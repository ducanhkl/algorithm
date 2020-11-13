#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test -- )
    {
        cin >> s;
        int l, r, u, d, il, ir, iu, id;
        l = r = u = d = il = ir = iu = id = 0;
        int x = 0, y = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int c = s[i];
            if (c == 'W')
            {
                y ++;
                if (y > u)
                {
                    u = y;
                    id = 0;
                    iu = 1;
                } else
                    if (y == u)
                    {
                        iu = 1;
                    }
            }
            if (c == 'S')
            {
                y --;
                if (y < d)
                {
                    d = y;
                    id = 1;
                    iu = 0;
                } else
                    if (y == d)
                    {
                        id = 1;
                    }
            }
            if (c == 'A')
            {
                x  --;
                if (x < l)
                {
                    l = x;
                    il = 1;
                    ir = 0;
                } else
                    if (x == l)
                    {
                        il = 1;
                    }
            }
            if (s[i] == 'D')
            {
                x ++;
                if (x > r)
                {
                    r = x;
                    il = 0;
                    ir = 1;
                } else
                    if (x == r)
                    {
                        ir = 1;
                    }
            }
        }
        long long dx = r-l+1;
        long long dy = u-d+1;
        long long area = dx*dy, tmp = area;
        if (dy > 2 && iu*id == 0)
        {
            area = tmp - dx;
        }
        if (dx > 2 && il*ir == 0)
        {
            area = min(area, tmp - dy);
        }
        cout << area <<  endl;
    }
    return 0;
}
