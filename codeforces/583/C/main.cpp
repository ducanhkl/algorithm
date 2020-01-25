#include <bits/stdc++.h>

using namespace std;

const int maxn = 600;
long long a[maxn*maxn];
int n;
vector <long long> v;
map <long long, int> m;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    n = n*n;
    for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            m[a[i]]++;
        }
    sort (a+1, a+n+1);
    for (int i = n; i >= 1; i--)
        {
            if (m[a[i]] > 0)
            {
                cout << a[i] << " ";
                for (int j = 0; j < v.size(); j++)
                    m[__gcd(a[i], v[j])] -= 2;
                v.push_back(a[i]);
                m[a[i]] --;
            }
        }
    return 0;
}
