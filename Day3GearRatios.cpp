#include <bits/stdc++.h>
using namespace std;

bool isSymbol(char ch)
{
    return (!isdigit(ch) && ch!='.') ;
}

bool isAdjToSymbol(vector<string> &v, int i, int j)
{
    if (i > 0)
    {
        if (isSymbol(v[i - 1][j]))
            return true;
        if (j > 0 && (isSymbol(v[i][j - 1]) || isSymbol(v[i - 1][j - 1])))
            return true;
        if (j < v[i].size() - 1 && (isSymbol(v[i][j + 1]) || isSymbol(v[i - 1][j + 1])))
            return true;
    }
    if (i < v.size() - 1)
    {
        if (isSymbol(v[i + 1][j]))
            return true;
        if (j > 0 && (isSymbol(v[i + 1][j - 1] || isSymbol(v[i][j - 1]))))
            return true;
        if (j < v[i].size() - 1 && (isSymbol(v[i][j + 1]) || isSymbol(v[i + 1][j + 1])))
            return true;
    }
    return false;
}

int main()
{
    string str;
    vector<string> s;
    while (getline(cin, str))
    {
        if (str.empty()) {
            break;
        }
        s.push_back(str);
    }
    int num = 0, ans = 0;
    bool valid = false;
    for (int i = 0; i < s.size(); i++)
    {
        if (valid)
        {
            ans += num; 
        }
        num = 0;
        valid = false;
        for (int j = 0; j < s[i].size(); j++)
        {
            if (isdigit(s[i][j]))
            {
                valid = valid || isAdjToSymbol(s, i, j);
                num = num * 10 + (s[i][j] - '0');
            }
            else
            {
                if (valid)
                {
                    ans += num;
                }
                num = 0;
                valid = false;
            }
        }
    }
    if (valid)
    {
        ans += num;
    }
    cout << ans;
}
