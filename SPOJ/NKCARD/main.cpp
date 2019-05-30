#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int m, k;
int first, second;
int a[2*maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    scanf("%d %d", &m, &k);
    for (int i = 0; i < m; i++)
        a[i] = i;
    first = 0, second = m-1;
    char x;
    while (scanf("%c", &x))
    {
        if (x == '.')
        {
            printf("%d %d %d", a[k+first-1], a[k+first], a[k+first+1]);
            return 0;
        }
        if (x == 'B')
        {
            swap(a[first], a[first+1]);
            a[++second] = a[first];
            first++;
        }
        if (x == 'A')
        {
            a[++second] = a[first];
            first++;
        }
    }
    return 0;
}
