#include <bits/stdc++.h>

using namespace std;


struct point
{
    int x; int y;
    data ()
    {

    }
    void in()
    {
        int _x, _y;
        cin >> _x >> _y;
        x = _x, y = _y;
    }
};

point p[20];

void check1()
{
    int l = min(p[1].y, min(p[2].y, min(p[3].y, p[4].y)));
    int r = max(p[1].y, max(p[2].y, max(p[3].y, p[4].y)));
    int u = min(p[1].x, min(p[2].x, min(p[3].x, p[4].x)));
    int d = max(p[1].x, max(p[2].x, max(p[3].x, p[4].x)));
    double _x = (p[8].x + p[5].x + p[6].x + p[7].x)/4.0;
    double _y = (p[5].y + p[6].y + p[7].y + p[8].y)/4.0;
    if (_y >= l && _y <= r && _x >= u && _x <= d)
    {
        cout << "YES";
        exit(0);
    }
    for (int i = 5; i <= 8; i++)
        if (p[i].y >= l && p[i].y <= r && p[i].x >= u && p[i].x <= d)
            {
                cout << "YES";
                exit(0);
            }
}

void check2()
{
    for (int i = 1; i <= 8; i++)
    {
        int _x = p[i].x;
        int _y = p[i].y;
        p[i].x = _x+_y;
        p[i].y = _x - _y;
    }
    for (int i = 1; i <= 4; i++)
        swap(p[i], p[i+4]);
    check1();
}
int main()
{
    //reopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    p[1].in(), p[2].in(), p[3].in(), p[4].in();
    p[5].in(), p[6].in(), p[7].in(), p[8].in();
    check1();
    check2();
    cout << "NO";
    return 0;
}
