#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+!00;
int dd[maxn];
string s;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while( test--)
    {
        memset(dd, 0, sizeof(dd));
        cin >> s;
        deque <int> q;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ')')
            {
                if (q.size() == 0)
                    continue;
                int pos = q.front();
                q.pop_front();
                dd[i] = dd[pos] = 1;
            }
            else
                q.push_front(i);
        }
        for (int i = 1; i < s.size(); i++)
            if (dd[i] != 0)
                dd[i] = dd[i-1] + dd[i];
        cout << *max_element(dd, dd+s.length()) << endl;
    }
    return 0;
}
