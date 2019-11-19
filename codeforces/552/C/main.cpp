#include <iostream>

using namespace std;

long long w, m;
int cnt = 0, c[60];

int main()
{
    cin >> w >> m;
    while (m != 0)
    {
        c[++cnt] = m%w;
        m /= w;
    }
    for (int i = 1; i <= cnt; i++)
        if (c[i] != 1 && c[i] != 0 && c[i] != w-1 && c[i] != w)
    {
        return cout << "NO", 0;
    } else
    {
        if (c[i] == w-1 || c[i] == w)
        {
            c[i+1]++;
        }
    }
    cout << "YES";
    return 0;
}
