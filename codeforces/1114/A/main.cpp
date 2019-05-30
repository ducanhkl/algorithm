    #include <bits/stdc++.h>

    using namespace std;

    int main()
    {
        //freopen("inp.txt", "r", stdin);
        int x, y, z, a, b, c;
        cin >> x >> y >> z >> a >> b >> c;
        if (a < x)
            return cout << "NO", 0;
        a -= min(a, x);
        if (a+b < y)
            return cout << "NO", 0;
        int _a = a;
        a -= min(a, y);
        y -= min(_a, y);
        b -= min(y, b);
        if (a+b+c < z)
            return cout << "NO", 0;
        cout << "YES";
        return 0;
    }
