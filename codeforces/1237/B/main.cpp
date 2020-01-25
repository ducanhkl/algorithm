#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5+100;
int n;
int a[maxn], b[maxn], dd[maxn];
int cnt = 0, top1, top2;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[n-i+1];
    for (int i = 1; i <= n; i++)
        cin >> b[n-i+1];
    top1 = n, top2 = n;
    while (top2 > 0)
    {
        while (dd[a[top1]])
            top1--;
        while (top2 > 0 && a[top1] != b[top2])
            {
                dd[b[top2]] = 1;
                cnt ++;
                top2--;
            }
        top1--;
        top2--;
    }
    cout << cnt;
    return 0;
}
