#include <bits/stdc++.h>

using namespace std;

long long p[50];

bool check(int f, long long c)
{
    if (c == p[f-1])
        return true;
    if (c < p[f-1])
        return  !check(f-1, p[f-1]-c);
    else return check(f-1, c-p[f-1]);
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    long long f, c;
    ios_base::sync_with_stdio(false);
    p[0] = 1;
    for (int i = 1; i <= 40; i++)
        p[i] = p[i-1] * 2LL;
    while(cin >> f >> c)
    {
        if (f == 0 && c == 0)
            return 0;
        if (check(f, c))
            cout << 'D' << endl;
        else cout << 'U' << endl;
    }
    return 0;
}
