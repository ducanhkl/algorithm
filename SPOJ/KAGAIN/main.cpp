#include <bits/stdc++.h>
#define maxn 1000006

using namespace std;

int t, n;
long long a[maxn], s[maxn], l[maxn], r[maxn];
long long ans = 0, top;
void init()
{
    ans = 0;
    memset(a ,0 , sizeof(a));
    memset(s ,0, sizeof(s));
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
}
int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        init();
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        memset(s, 0, sizeof(s));
        top = 0;
        for (int i = 1; i <= n; i++)
        {
            while(a[i] <= a[s[top]] && top != 0)
                top--;
            if (top == 0)
                l[i] = 0;
            else l[i] = s[top];
            s[++top] = i;
        }
        memset(s, 0, sizeof(s));
        top = 0;
        for (int i = n; i >= 1; i --)
        {
            while(a[i] <= a[s[top]] && top != 0)
                top--;
            if (top == 0)
                r[i] = n+1;
            else r[i] = s[top];
            s[++top] = i;
        }
        int _l = 0, _r = 0;
        for (int i = 1; i <= n; i++)
            if ((a[i]*((r[i]-1)-(l[i]+1)+1)) > ans)
        {
            ans = a[i]*((r[i]-1)-(l[i]+1)+1);
            _l = l[i] + 1;
            _r = r[i] - 1;
        }
        cout << ans << " " << _l << " " << _r << endl;
    }
    return 0;
}
