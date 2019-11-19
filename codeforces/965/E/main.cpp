/*
#include <bits/stdc++.h>
#define maxn 100005

using namespace std;

int n;
long long ans;
string s[maxn], res[maxn];

void init(int l, int r, int p)
{
    for (int i = l, j = l; j <= r; i++)
        if (i == r || s[j][p] != s[i+1][p])
    {
        if (s[j].length() == p+1)
            init(j+1, i, p+1);
        else
        {
            init(j, i, p+1);
            int x = j;
            for (int k = j; k <= i; k++)
                if (res[k].length() > res[x].length())
                        x = k;
            res[x] = "";
            sort(res+j, res+i+1);
        }
        for (int k = j; k <= i; k++)
            res[k] = s[k][p] + res[k];
        j = i+1;
    }
}

int main()
{
    //freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    sort(s+1, s+n+1);
    init(1, n, 0);
    for (int i = 1; i <= n; i++)
        ans += res[i].length();
    cout << ans;
    return 0;
}
*/

#include <bits/stdc++.h>

using namespace std;

char operators [4] = {'+','-','*','/'}, roundbrackets[2] = {'(',')'} ;
bool isOperand(char test) {
    for (int i = 0; i < 4 ; i ++)
        if (test == operators[i])
            return false ;
    return true ;
}
int piority(char check)  {
    if  (check ==  '+' || check == '-')
        return 0 ;
    else return 1 ;
}
bool isOperator(char test){
    for (int i = 0; i < 4; i ++)
        if (test == operators[i]) return true ;
    return false  ;
}
bool isRoundBracket(char test){
    for  (int i = 0; i < 2;  i ++)
         if  (test == roundbrackets[i]) return   true ;
    return false               ;
}
void InfixtoPrefix(string input, int i )
{
    stack <char> s;
    int j = 0;
    if (isOperator(input[i]))
    {
        if (s.empty())
            s.push(input.at(i)) ;
        else{
            for (j = i - 1; !isRoundBracket(input[j]) && j >= 0 && j < input.length(); j -- )    {
                if (isOperator(input.at(j))) {
                    stack <char> store ;
                    while (piority(input[j]) > piority(s.top()) ) {
                        store.push(s.top())  ;
                        s.pop() ;
                    }
                    if (piority(input[j]) == piority(s.top())) {
                        s.push(input[j]);
                    }
                }
            }
        }
     }
    while(!s.empty()){
        cout << s.top() ;
        s.pop() ;
    }
    for (j; j != isRoundBracket(input[j])  &&  j < input.length(); j ++)
        if (isOperand(input[j]))
            cout << input.at (j )  ;
}
int main()
{
     string input ;
     getline(cin,input) ;
     for (int i = 0; i < input.length(); i ++) {
        InfixtoPrefix(input,i) ;
     }
    return 0;
}
