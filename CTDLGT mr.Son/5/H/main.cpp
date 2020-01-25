#include <bits/stdc++.h>

using namespace std;


struct
{
    int x, y, z;
};

deque <data> q;

int main()
{
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test --)
    {
        cin >> a >> b >> c;
        for (int i = 1; i <= a; i++)
            for (int j = 1; j <= b; j++)
                for (int h = 1; h <= c; h++)
        {
            char x;
            cin >> x;
            if (x == s)
                q.push_back(x);
            if (x == '#')
                rec[i][j][k] = 1;
        }
    }
    while (q.size())
    {
        data u = q.front;

    }
    return 0;
}
