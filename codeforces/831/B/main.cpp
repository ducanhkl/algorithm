#include <bits/stdc++.h>
#define maxn 256
using namespace std;

string f, s, k;
char a[maxn];

int main()
{
    freopen("inp.txt", "r", stdin);
    cin >> f;
    cin >> s;
    cin >> k;
    for (int i = 0; i < sizeof(s); i++)
        a[(int)f[i]] = s[i];
    for (int i = 0; i< k.length(); i++)
        cout << a[(int)k[i]];
    return 0;
}
