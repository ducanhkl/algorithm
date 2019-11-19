#include <bits/stdc++.h>
#define maxn 1000001
#define maxc 1e9+7

using namespace std;


using namespace std;

string s, t;
int next[maxn]; // hau to cua t1t2t3..ti trung voi t1t2t3..tj

int main() {
    //freopen("inp.txt", "r", stdin);
    cin >> s >> t;
    s = " " + s;
    t = " " + t;
    int j = next[1] = 0;
    for (int i  = 2; i < t.length(); i++)
    {
        while (j > 0 && t[j+1] != t[i])
            j = next [j];
        if (t[j+1] == t[i])
            j ++;
        next[i] = j;
    }
    j = 0;
    for (int i = 1; i < s.length(); i++)
    {
        while (j != 0 && t[j+1] != s[i])
            j = next[j];
        if (t[j+1] == s[i])
            j++;
        if (j >= t.length() - 1)
            cout << i - j + 1 << " ";
    }
    return 0;
}
