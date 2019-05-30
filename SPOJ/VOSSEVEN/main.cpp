#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int a[maxn], n = 0;
long long sl[maxn], cnt[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    char x;
    while (cin >> x)
        a[++n] = x-'0';
    for (int i = 1; i <= n; i++)
        if (a[i] == 7)
            sl[i] = sl[i-1]+1;
        else
            sl[i] = 0;
    for (int i = 1; i <= n; i++)
        cnt[sl[i]] ++;
    for (int i = n; i >= 1; i--)
        cnt[i] += cnt[i+1];
    for (int i = 1; i <= n; i++)
        if (cnt[i])
            printf("%d %lld \n", i, cnt[i]);
    return 0;
}
