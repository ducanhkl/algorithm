#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int a[maxn], b[maxn];
int n, cnt1, cnt2 = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    if (n == 3)
        return cout << "1 1 3", 0;
    int p = 1;
    for (int i = 1; i <= n; i++)
        a[i] = i;
    cnt1 = n;
    while (cnt1 > 1)
        {
            if (cnt1 == 3)
            {
                cout << p << " " << p << " " << p*3;
                exit(0);
            }
            for (int j = 1; j <= cnt1; j++)
                if (a[j] % 2 == 0)
                    b[++cnt2] = j/2;
            for (int j = cnt2+1; j <= cnt1; j++)
                cout << p*a[1] << " ";
            p *= 2;
            cnt1 = cnt2;
            cnt2 = 0;
            swap(a, b);
        }
    cout << p*a[1];
    return 0;
}
