#include <bits/stdc++.h>

using namespace std;

int n, t;
int cnt[20];
string s;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> t;
    while(t--)
    {
        cin >> s;
        int n = s.length()-1;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i <= n; i++)
            cnt[s[i] - '0']++;
        if (s[0] == '1' && (n-(int)(s[n] != '0') == cnt[0]) && (s[n] == '1' || s[n] == '0'))
        {
            for (int i = 1; i < n; i++)
                cout << 9;
            cout << endl;
            continue;
        }
        for (int i = n; i >= 0; i--)
        {
            bool check = false;
            cnt[s[i] - '0'] --;
            for (int j = s[i]-'0'-1; j >= 0; j--)
            {
                int temp = 0;
                cnt[j]++;
                for (int k = 0; k <= 9; k++)
                    temp += cnt[k]%2;
                if (temp > n-i)
                {
                    cnt[j]--;
                    continue;
                }
                for (int k = 0; k < i; k++)
                    cout << s[k];
                cout << j;
                for (int k = i+1; k <= n-temp; k++)
                    cout << 9;
                for (int k = 9; k >= 0; k--)
                    if (cnt[k]%2)
                        cout << k;
                cout << endl;
                check = true;
                break;
            }
            if (check)
                break;
        }
    }
}
