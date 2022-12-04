#include <iostream>

using namespace std;

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int test;
    cin >> test;
    while(test--)
    {
        string s;
        cin >> s;
        int l = 0, r = s.length()-1;
        while(l <= r && s[l] == s[r])
        {
            l++;
            r--;
        }
        while(l <= r && s[l] == s[l+1])
        {
            l += 2;
        }
        if (l <= r)
            cout << "Alice";
        else
            cout << "Draw";
        cout << endl;
    }
    return 0;
}
