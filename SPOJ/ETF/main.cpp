#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int f[maxn], n, x;
void init()
{
    for (int i = 1; i < maxn; i++)
        if (i%2 == 0)
            f[i] = i/2;
        else f[i] = i;
    for (int i = 3; i < maxn; i++)
        if (f[i] == i)
            for (int j = i; j < maxn; j += i)
                f[j] = f[j]/i*(i-1);
}
int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    init();
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        cout << f[x] << endl;
    }
    return 0;
}
