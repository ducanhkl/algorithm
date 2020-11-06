#include <bits/stdc++.h>

using namespace std;

const int maxn = 4e5+100;

int n;
long long s[maxn], spre[maxn], pre[maxn];

struct line
{
    long long a;
    long long b;
};

vector <long double> vp;
vector <line> vl;



long double intersect(line x,line y)
{
	if(x.a == y.a)
        return 1e15;
	return ( long double) (y.b-x.b)/(long double)(x.a-y.a);
}

long long getVal(long long x, line l)
{
    return x*l.a + l.b;
}

long long get(long long x)
{
    int pos = lower_bound(vp.begin(), vp.end(), x) - vp.begin();
    // cout << pos << " " << vl[pos].a << " ";
    return getVal(x, vl[pos]);
}


void add(line l)
{
    if (vl.empty())
    {
        vl.push_back(l);
        return;
    }
    if (vl.size() == 1)
    {
        vp.push_back(intersect(vl.back(), l));
        vl.push_back(l);
        return ;
    }
    while (vl.size())
    {
        line l1 = vl.back();
        vl.pop_back();
        if (intersect(l1, l) <= vp.back())
        {
            vp.pop_back();
        } else
        {
            vl.push_back(l1);
            break;
        }
    }

    vp.push_back(intersect(l, vl.back()));
    vl.push_back(l);
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
        spre[i] = spre[i-1] + s[i]*i,
        pre[i] = pre[i-1] + s[i];
    long long ans = 0;
    line l;
    l.a = l.b = 0;
    add(l);
    for (int i = 1; i <= n; i++)
    {
        long long res = get(-pre[i]) + spre[i];
        // cout << res << endl;
        ans = max(ans, res);
        l.a = i;
        l.b = pre[i]*i - spre[i];
        add(l);
    }
    cout << ans;
    return 0;
}
