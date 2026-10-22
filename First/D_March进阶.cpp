#include <bits/stdc++.h>
using namespace std;
bool inIsValid(char op1, char op2)
{
    // 优先级
    int p[200] = {0};
    p['<'] = 1;
    p['('] = 2;
    p['['] = 3;
    p['{'] = 4;
    if (p[op1] < p[op2])
        return true;
    return false; 
}
bool isValid(string &s)
{
    stack<char> st;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '<' || s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            // 碰见左括号先判断是否是合法嵌套
            if (!st.empty())
            {
                if (!inIsValid(s[i], st.top()))
                    return false;
            }
            st.push(s[i]);
        }
        else if (s[i] == '>' || s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if (s[i] == '>')
            {
                if (st.empty() || st.top() != '<')
                {
                    return false;
                }
            }
            else if (s[i] == ')')
            {
                if (st.empty() || st.top() != '(')
                {
                    return false;
                }
            }
            else if (s[i] == ']')
            {
                if (st.empty() || st.top() != '[')
                {
                    return false;
                }
            }
            else if (s[i] == '}')
            {
                if (st.empty() || st.top() != '{')
                {
                    return false;
                }
            }
            //出栈
            st.pop();
        }
    }
    //检查剩余括号一定
    if(!st.empty()) return false;
    return true;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        // 读取字符串
        string s;
        cin >> s;
        if(isValid(s)) {
            cout << "Match" << endl;
        } else{
            cout << "Fail" << endl;
        }
    }
    return 0;
}
