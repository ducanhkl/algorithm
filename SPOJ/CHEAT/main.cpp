#include <bits/stdc++.h>
#define maxn 100001

using namespace std;

int n;
int a[maxn], Next[maxn], pre[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        Next[i] = i+1;
    for (int i = 1; i <= n; i++)
        pre[i] = i-1;
    int last = 0;
    for (int i =1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x != pre[last] && x < last)
            return cout << "YES", 0;
        Next[pre[x]] = Next[x];
        pre[Next[x]] = pre[x];
        last = x;
    }
    cout << "NO";
    return 0;
}
