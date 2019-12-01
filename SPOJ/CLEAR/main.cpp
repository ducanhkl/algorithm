    #include <bits/stdc++.h>

using namespace std;

const long long maxc = 81*20;

long long m;
long long dp[20][maxc][2];
long long rn[maxc];
string s;

long long getval(long long n)
{
    string s = to_string(n);
    long long ans = 0;
    for (long long i = 0; i < s.size(); i++)
    {
        long long val = s[i] - '0';
        ans += val*val;
    }
    return ans;
}

void init()
{
    rn[0] = 0;
    rn[1] = 1;
    long long dd[maxc+10];
    for (long long i  = 2; i < maxc; i++)
    {
        memset(dd, 0, sizeof(dd));
        long long v = i;
        while (true)
        {
            dd[v] = true;
            v = getval(v);
            if (dd[v] || v == 1)
                break;
        }
        rn[i] = (v == 1);
    }
}

long long gen(long long pos, long long sum, long long ok)
{
    if (dp[pos][sum][ok] != -1)
        return dp[pos][sum][ok];
    if (pos == s.size()-1)
        return dp[pos][sum][ok] = rn[sum];
    long long &res = dp[pos][sum][ok] = 0;
    for (long long i = min(9*(1-ok), (int)s[pos+1]-'0'); i <= 9; i++)
    {
        res += gen(pos+1, sum+i*i, ok || (i > (s[pos+1]-'0')));
    }
    return  res;
}

void getans(string &res, long long pos, long long sum, long long ok)
{
    if (m == 0)
        return ;
    for (long long i = min(9*(1-ok), (int)s[pos]-'0'); i <= 9; i++)
    {
        if (m > dp[pos][sum+i*i][ok || (i > (s[pos]-'0'))])
            m -= max(dp[pos][sum+i*i][ok || (i > (s[pos]-'0'))], 0LL);
        else
        {
            res = res + (char)(i+'0');
            getans(res, pos+1, sum+i*i, ok || (i > (s[pos]-'0')));
            return;
        }
    }
}

void solve(long long n)
{
    memset(dp, -1, sizeof(dp));
    s = to_string(n);
    while (s.size() < 18)
        s = "0" + s;
    for (long long i = 0; i <= 9; i++)
    {
        if(i == 0)
            gen(0, 0, 0);
        else
            gen(0, i*i, 1);
    }
    if (rn[getval(n)])
        m++;
    string ans = "";
    getans(ans, 0, 0, 0);
    while (ans.size() < 18)
        ans = ans + "0";
    while (ans[0] == '0')
        ans.erase(0, 1);
    cout << ans << endl;
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    long long test;
    cin >> test;
    init();
    while (test--)
    {
        long long n;
        cin >> n >> m;
        solve(n);
    }
    return 0;
}
