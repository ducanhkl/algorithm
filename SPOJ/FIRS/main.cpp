#include <bits/stdc++.h>
#define maxn 1000005

using namespace std;

int n;
int a[maxn];
int dd[maxn];
map <pair <int, int>, int > m;

int main()
{
    memset(dd, 0, sizeof(dd));
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], m[{a[i], i}] ++;
    int dem = 0;
    while (m.size())
    {
        //cout << m.size() << endl;
        map <pair <int, int>, int >::iterator it;
        dem ++;
        pair <int, int> x = m.begin()->first;
        it = m.find(x);
        m.erase(it);
        if (x.second != 1 && dd[x.second-1] != 1)
            {
                pair <int, int> x1 = make_pair(a[x.second-1], x.second-1);
                it = m.find(x1);
                m.erase(x1);
            }
        if (x.second != n && dd[x.second +1] != 1)
            {
                pair <int, int> x2 = make_pair(a[x.second+1], x.second+1);
                it = m.find(x2);
                m.erase(x2);
            }
    }
    cout << dem;
    return 0;
}
