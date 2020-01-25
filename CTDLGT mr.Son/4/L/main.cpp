#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+100;
long long l[maxn], r[maxn], s[maxn];
int n;
long long a[maxn];

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test--)
    {
        cin >> n;
        for (int i =  1; i <= n; i++)
            cin >> a[i];
        long long ans = 0;
        memset(l, 0, sizeof(l));
        memset(r, 0, sizeof(r));
        memset(s, 0, sizeof(s));
        int top = 0;
        for (int i = 1; i <= n; i++)
        {
            while (top && a[i] <= a[s[top]])
                top--;
            if (top == 0)
                l[i] = 0;
            else
                l[i] = s[top];
            s[++top] = i;
        }
        memset(s, 0, sizeof(s));
        top = 0;
        for (int i = n; i >= 1; i--)
        {
            while (top && a[i] <= a[s[top]])
                top--;
            if (top == 0)
                r[i] = n+1;
            else
                r[i] = s[top];
            s[++top] = i;
        }
        for (int i = 1; i <= n; i++)
            ans = max(ans, (r[i]-l[i]-1)*a[i]);
        cout << ans << endl;
    }
    return 0;
}
