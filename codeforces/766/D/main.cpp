#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

int n, m, q;
string s;
map <string, int> ma;
int root[2*maxn];

int getroot(int u)
{
    if (root[u] == u)
        return u;
    else
        return root[u] = getroot(root[u]);
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    memset(root, 0, sizeof(root));
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        ma[s] = i;
        root[i] = i;
        root[n+i] = n+i;
    }
    for (int i = 1; i <= m; i++)
    {
        int t;
        string a, b;
        cin >> t >> a >> b;
        int A = ma[a], B = ma[b];
        if (t == 1)
        {
            if (getroot(A) == getroot(B+n))
            {
                cout << "NO" << endl;
                continue;
            }
            if (getroot(A) != getroot(B))
                root[root[A]] = B;
            if (getroot(A+n) != getroot(B+n))
                root[root[A+n]] = B+n;
            cout << "YES" << endl;
        } else
        {
            if (getroot(A) == getroot(B))
            {
                cout << "NO" << endl;
                continue;
            }
            if (getroot(A) != getroot(B+n))
                root[root[A]] = B+n;
            if (getroot(A+n) != getroot(B))
                root[root[B]] = A+n;
            cout << "YES" << endl;
        }
    }
    for (int i = 1; i <= q; i++)
    {
        string a, b;
        cin >> a >> b;
        int A = ma[a], B = ma[b];
        if (getroot(A) != getroot(B) && getroot(A) != getroot(B+n))
        {
            cout << 3 << endl;
            continue;
        }
        if (getroot(A) == getroot(B))
            cout << 1;
        else cout << 2;
        cout << endl;
    }
}
