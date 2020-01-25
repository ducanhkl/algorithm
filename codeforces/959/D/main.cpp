#include <bits/stdc++.h>
#define maxn 100006
#define MM 5050505 + 1

using namespace std;

int a[maxn], n, dd[MM];

int update (int x)
{
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
    {
        for (int j = i; j < MM; j += i)
            dd[j] = 1;
        while (x % i == 0)
            x /= i;
    }
    if (x > 1)
        for (int j = x; j < MM; j += x)
            dd[j] = 1;
    return 0;
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int i;
    for (i = 1; i <= n; i++)
        if (dd[a[i]])
            break;
        else
            update(a[i]), cout << a[i] << " ";
    for (int j = a[i]; j < MM, i <= n; j++)
        if (dd[j] == 0)
    {
        cout << j << " ";
        update(j);
        i++;
        break;
    }
    for (int j = 2; j < MM && i <= n; j ++)
        if (dd[j] == 0)
    {
        cout << j << " ";
        update(j);
        i++;
    }
    return 0;
}
