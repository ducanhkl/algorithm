#include <bits/stdc++.h>
#define maxn 10005

using namespace std;

int n;
int a[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    int aa, ab, aba, abab;
    aa = ab = aba = abab = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
            aa++, aba ++;
        else ab ++, abab++;
        ab = max(aa, ab);
        aba = max(aba, ab);
        abab = max(abab, aba);
    }
    cout << max(aa, max(ab, max(aba, abab)));
    return 0;
}
