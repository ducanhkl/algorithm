#include <bits/stdc++.h>
#define maxn 900

using namespace std;

string s;
int n;
int pos[maxn], l[maxn], r[maxn];
stack<int> st;

int main()
{

    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i] >> r[i];
        pos[i] = s.length();
        s = s+ '(';
        st.push(i);
        while (st.size() && pos[st.top()]+l[st.top()] <= s.length())
        {
            if (pos[st.top()] + r[st.top()] < s.length())
                return cout << "IMPOSSIBLE", 0;
            s = s +')';
            st.pop();
        }
    }
    if (st.size())
        cout << "IMPOSSIBLE";
    else
        cout << s;
    return 0;
}
