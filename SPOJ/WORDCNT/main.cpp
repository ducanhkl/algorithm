#include <bits/stdc++.h>

using namespace std;

int t;
string s;

int main()
{
    //freopen("inp.txt", "r", stdin);
    scanf("%d\n", &t);
    for (int j = 1; j <= t; j++)
    {
        getline(cin, s);
        //cout << s;
        string str = "";
        int a[100], dem = 0;
        memset(a, 0, sizeof(a));
        for (int i = 0; i < s.length(); i++)
            if (s[i] == ' ')
                if (str == "")
                    continue;
                else a[++dem] = str.length(), str = "";
            else str = str + s[i];
        if (str != "")
            a[++dem] = str.length();
        int ans = 0,d = 1;;
        for (int i = 2; i <= dem; i++)
            if (a[i] == a[i-1])
                d++, ans = max(ans, d);
            else d = 1;
        cout << ans <<endl;
    }
    return 0;
}
