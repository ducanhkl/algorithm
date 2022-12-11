#include <bits/stdc++.h>

using namespace std;

int n;
string a, b;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while (test --)
    {
        cin >> n >> a >> b;
        map<pair<int, int>, int> m;
        int c_odd_pair = 0, c_similar_pair = 0;
        for (int i = 0; i < n; i++)
        {
            int f = a[i];
            int s = b[n-i-1];
            if (f > s)
            {
                swap(f, s);
            }
            if (m[ {f, s}])
            {
                int now = ++m[ {f, s}];
                if (now%2)
                {
                    c_odd_pair++;
                    if (f == s)
                    {
                        c_similar_pair ++;
                    }
                }
                else
                {
                    c_odd_pair --;
                    if (f == s)
                    {
                        c_similar_pair --;
                    }
                }
            }
            else
            {
                m[{f, s}]++;
                c_odd_pair++;
                if (f == s)
                {
                    c_similar_pair ++;
                }
            }
        }
        if (n % 2 == c_similar_pair  && c_similar_pair == c_odd_pair)
        {
            cout << "YES";
        } else
        {
            cout << "NO";
        }
        cout << endl;
    }
    return 0;
}

