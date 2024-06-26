#include <bits/stdc++.h>

using namespace std;

string c[70][70], f[100];
int n, t;

string operator + (string a, string b)
{
    string res="";
    while(a.length() < b.length()) a="0"+a;
    while(b.length() < a.length()) b="0"+b;
    int carry=0;
    for(int i=a.length()-1;i>=0;i--)
    {
        int tmp=a[i]-48 + b[i]-48 + carry;
        carry=tmp/10;
        tmp=tmp%10;
        res=(char)(tmp+48)+res;
    }
    if(carry>0) res="1"+res;
    return res;
}

string operator - (string a, string b)
{
    string res="";
    while(a.length() < b.length()) a="0"+a;
    while(b.length() < a.length()) b="0"+b;
    bool neg=false;
    if(a<b)
    {
        swap(a,b);
        neg=true;
    }
    int borrow=0;
    for(int i=a.length()-1; i>=0;i--)
    {
        int tmp=a[i]-b[i]-borrow;
        if(tmp<0)
        {
            tmp+=10;
            borrow=1;
        }
        else borrow=0;
        res=(char)(tmp%10 + 48) + res;
    }
    while(res.length()>1 && res[0]=='0') res.erase(0,1);
    if(neg) res="-"+res;
    return res;
}

string operator * (string a, string b)
{
    string res="";
    int n=a.length();
    int m=b.length();
    int len=n+m-1;
    int carry=0;
    for(int i=len;i>=0;i--)
    {
        int tmp=0;
        for(int j=n-1;j>=0;j--)
            if(i-j<=m && i-j>=1)
            {
                int a1=a[j]-48;
                int b1=b[i-j-1]-48;
                tmp+=a1*b1;
            }
            tmp+=carry;
            carry=tmp/10;
            res=(char)(tmp%10 + 48)+res;
    }
    while(res.length()>1 && res[0]=='0') res.erase(0,1);
    return res;
}
void init()
{
    for (int i = 0; i < 60; i++)
        for (int j = 0; j < 60; j++)
            f[i] = "0", c[i][j] = "0";
    for (int i = 0; i < 60; i++)
        for (int j = 0; j <= i; j++)
            if (i == 0 || j == 0)
                c[i][j] = "1";
            else c[i][j] = c[i-1][j] + c[i-1][j-1];
    f[0] = "1";
    for (int i = 0; i <= 50; i++)
        for (int j = 0; j < i; j ++)
            f[i] = f[i] + c[i-1][j]*f[j];
}
int main()
{
    freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    init();
    while(cin >> n)
    {
        if (n == 0)
            break;
        cout << n << " " << f[n] << endl;
    }
    return 0;
}
