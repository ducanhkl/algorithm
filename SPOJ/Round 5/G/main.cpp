#include <bits/stdc++.h>

using namespace std;

long long c, hr, hb, wr, wb, kq = -1;

int main()
{
    //freopen("inp.txt", "r", stdin);
    cin >> c >> hr >> hb >> wr >> wb;
    for (int i = 0; i*wr <= c; i ++)
        kq = max(kq, i*hr + ((c - i*wr)/wb)*hb);
    cout << kq;
    return 0;
}
