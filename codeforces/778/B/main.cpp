#include <bits/stdc++.h>
#define maxn 5500

using namespace std;

string mn, mx, var, var1, var2, op, v[maxn], o[maxn];
int n, mm, c[maxn], a[maxn], b[maxn], cnt = 0;
map <string, int> m;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> mm;
    for (int i = 1; i <= mm; i++) mn += "0", mx += "1";
    m["?"] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> var >> op;
        m[var] = i;
        cin >>  var1;
        if (!(var1[0] == '1' || var1[0] == '0'))
        {
            cin >> op >> var2;
            o[i] = op;
            a[i] = m[var1];
            b[i] = m[var2];
        }
        else v[i] = var1;
    }
    for (int i = 0;i < mm; i++)
        for (int j = 0; j <= 1; j++)
    {
        memset(c, 0, sizeof(c));
        c[0] = j;
        int res = 0;
        for (int k = 1; k <= n; k++)
            if (o[k] == "")
                c[k] = (v[k][i] == '1'), res += c[k];
            else
            {
                int A = c[a[k]], B = c[b[k]];
                if (o[k] == "AND")
                    c[k] = A&B;
                if (o[k] == "OR")
                    c[k] = A|B;
                if (o[k] == "XOR")
                    c[k] = A^B;
                res += c[k];
            }
        if (c[0] == 0 || cnt > res)
            mn[i]  = '0' + c[0];
        if (c[0] == 0 || cnt < res)
            mx[i] = '0' + c[0];
        cnt = res;
    }
    cout << mn << endl;
    cout << mx;
    return 0;
}
