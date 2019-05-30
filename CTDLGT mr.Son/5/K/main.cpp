/*#include <bits/stdc++.h>

using namespace std;

struct data
{
    int a[10];
    int d;
} s, f;

int l[] = {3, 0, 2, 7, 4 , 1, 6, 8, 5, 9};
int r[] = {0, 4, 1, 3 , 8 , 5, 2, 7, 9, 6};

deque <data> q;

bool check_equal(data x, data y)
{
    for (int i = 0; i < 10; i++)
        if (x.a[i] != y.a[i])
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < 10; i++)
        cin >> s.a[i];
    int b[] = {1, 2, 3, 8, 0, 0, 4, 7, 6, 5};
    for (int i = 0; i < 10; i++)
        f.a[i] = b[i];
    s.d = 0;
    q.push_back(s);
    while (q.size())
    {
        data u = q.front();
        q.pop_front();
        data tmp;
        for (int i = 0; i < 10; i++)
            tmp.a[i] = u.a[l[i]];
        tmp.d = u.d+1;
        if (check_equal(tmp, f))
        {
            cout << tmp.d;
            return 0;
        }
        q.push_back(tmp);
        for (int i = 0; i < 10; i++)
            tmp.a[i] = u.a[r[i]];
        tmp.d = u.d+1;
        if (check_equal(tmp, f))
        {
            cout << tmp.d;
            return 0;
        }
        q.push_back(tmp);
    }
    return 0;
}
*/
#include <bits/stdc++.h>

using namespace std;
const string base = "1238004765";
typedef map <string, bool> msb;
typedef pair<string,int> psi;
string tleft(string s)
{
    string ss=s;
    ss[0] = s[3];
    ss[1] = s[0];
    ss[2] = s[2];
    ss[3] = s[7];
    ss[4] = s[4];
    ss[5] = s[1];
    ss[6] = s[6];
    ss[7] = s[8];
    ss[8] = s[5];
    ss[9] = s[9];
    return ss;
}
string tright(string s)
{
    string ss = s;
    ss[0] = s[0];
    ss[1] = s[4];
    ss[2] = s[1];
    ss[3] = s[3];
    ss[4] = s[8];
    ss[5] = s[5];
    ss[6] = s[2];
    ss[7] = s[7];
    ss[8] = s[9];
    ss[9] = s[6];
    return ss;
}
string bd;
int main()
{
    ios_base::sync_with_stdio(false);
    for (int i =0;i<10;i++)
    {
        int temp;
        cin >> temp;
        bd+=(char)(temp+'0');
    }
    queue <psi> bla;
    msb cla;
    bla.push(psi(bd,0));
    cla[bd]=true;
    while (bla.size())
    {
        psi top = bla.front();
        bla.pop();
        if (top.first == base) return cout << top.second , 0;
        string tl = tleft(top.first);
        if (cla[tl]==false)
        {
            cla[tl]=true;
            bla.push(psi(tl,top.second+1));
        }
        string tr = tright(top.first);
        if (cla[tr]==false)
        {
            cla[tr]=true;
            bla.push(psi(tr,top.second+1));
        }
    }
    return 0;
}
