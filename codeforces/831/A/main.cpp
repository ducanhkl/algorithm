#include <bits/stdc++.h>>
#define maxn 101

using namespace std;

int a[maxn], b[maxn], c[maxn];
int n;
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1;i < n; i++)
    {
        if (a[i] < a[i+1])
            b[i] = 0,c[i] = 0;
        if (a[i] == a[i+1])
            b[i] = 1, c[i] = 1;
        if (a[i] > a[1+i])
            b[i] = 2, c[i] =2;
    }
    sort (b+1, b+n);
    for (int i = 1; i < n; i++)
        if (b[i] != c[i])
    {
        cout << "No";
        return 0;
    }
    cout << "Yes";
    return 0;
}
