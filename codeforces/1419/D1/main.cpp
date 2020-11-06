#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;

int a[maxn], b[maxn];
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    int cnt = n;
    for (int i = n; i >= 1; i -= 2)
    {
        b[i] = a[cnt--];
    }
    for (int i = n-1; i >= 1; i -= 2)
    {
        b[i]= a[cnt--];
    }
    int num = 0;
    for (int i = 2; i < n; i++)
        if (b[i] < b[i-1] && b[i] < b[i+1])
            num ++;
    cout << num << endl;
    for (int i = 1; i<= n; i++)
        cout << b[i] << " ";
    return 0;
}
