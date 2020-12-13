#include <bits/stdc++.h>

using namespace std;

/*

long long dp[20][20][20][2];
long long a1[20];
int d, k;

bool check(int x, int y)
{
    return abs(x-y) > d;
}




long long get_ans(long long x)
{
    memset(a1, 0, sizeof(a1));
    memset(dp, 0, sizeof(dp));
    int len = 0;
    while (x != 0)
    {
        a1[++len]= x%10;
        x /= 10;
    }
    long long ans = 0;
    for (int i = 0; i <= 9; i++)
    {
        dp[1][i][0][0] = dp[1][i][0][1] = 1;
    }
    for (int i = 2; i <= len; i ++)
    {
        if (i == 2)
        {
            i ++;
            i--;
        }
        for (int kk = 0; kk <= k; kk++)
        {
            for (int j = 0; j <= 9; j++)
            {
                for (int oj = 0; oj <= 9; oj++)
                {
                    if (check(j, oj))
                    {
                        dp[i][j][kk][0] += dp[i-1][oj][kk][0];
                    }
                    else
                    {
                        if (k > 0)
                        {
                            dp[i][j][kk][0] += dp[i-1][oj][kk-1][0];
                        }
                    }
                }
            }
            // cout << i << endl;
            for (int oj = 0; oj < a1[i-1]; oj ++)
            {
                if (check(oj, a1[i]))
                {
                    dp[i][a1[i]][kk][1] += dp[i-1][oj][kk][0];
                }
                else
                {
                    dp[i][a1[i]][kk][1] += dp[i-1][oj][kk-1][0];
                }
            }
            if (check(a1[i-1], a1[i]))
            {
                dp[i][a1[i]][kk][1] += dp[i-1][a1[i-1]][kk][1];
            }
            else
            {
                dp[i][a1[i]][kk][1] += dp[i-1][a1[i-1]][kk-1][1];
            }
        }
    }
    for (int i = 0; i <= k; i++)
    {
        ans += dp[len][a1[len]][i][1];
        for (int j = 1; j < len; j++)
        {
            for (int x = 1; x <= 9; x++)
            {
                ans += dp[j][x][i][0];
            }
        }
        for (int j = 1; j < a1[len]; j++)
        {
            ans += dp[len][j][i][0];
        }
    }
    return ans;
}
*/

long long dp[20][20][2][2][20];

int d, k;

bool check(int x, int y)
{
    return abs(x-y) > d;
}

vector <int> num;
// f co phai max hay hong, 1 tuc la co, 0 tuc la khong

long long solve(int pos, int cnt, int f, int is_zero, int pre_num)
{
    if (cnt > k)
    {
        return 0;
    }
    if (pos == num.size())
    {
        if (is_zero == 1)
            return 0;
        return cnt <= k;
    }
    if (dp[pos][cnt][f][is_zero][pre_num] != -1)
    {
        return dp[pos][cnt][f][is_zero][pre_num];
    }
    int max_num;
    if (f == 1)
    {
        max_num = num[pos];
    } else
    {
        max_num = 9;
    }
    long long ans = 0;
    for (int i = 0; i <= max_num; i++)
    {
        int new_is_zero = is_zero;
        if (i != 0)
        {
            new_is_zero = 0;
        }
        int new_f = f;
        if ( ! (f && i == max_num))
        {
            new_f = 0;
        }
        int new_cnt = cnt + (!check(i, pre_num))*(!is_zero);
        if (new_cnt <= k)
            ans += solve(pos+1, new_cnt, new_f, new_is_zero, i);
    }
    return dp[pos][cnt][f][is_zero][pre_num] = ans;
}

long long get_ans(long long x)
{
    long long ans;
    memset(dp, -1, sizeof(dp));
    num.clear();
    while (x != 0)
    {
        num.push_back(x % 10);
        x /= 10;
    }
    reverse(num.begin(), num.end());
    ans = solve(0, 0, 1, 1, 0);
    return ans;
}


int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    long long a, b;
    cin >> a >> b >> d >> k;
    long long res2 = get_ans(b);
    long long res1 = get_ans(a-1);
    cout <<res2 - res1;
    return 0;
}
