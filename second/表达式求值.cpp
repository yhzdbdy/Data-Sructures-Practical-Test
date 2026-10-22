#include<bits/stdc++.h>
using namespace std;
/*处理的核心就是s[i]的优先级如果小于等于栈顶优先级就要先运算完栈顶的运算符再压栈*/
/*但是我们有一个注意的点就是 ^ 它是一个右结合运算符，s[^] 要先于 st[^] 运算*/
int In[100];
int Out[100];

//快速幂
int FE(int a, int b) {
    if(b == 0) return 1;
    int n = FE(a, b / 2);
    if(b % 2 == 1) return n * n * a;
    else if(b % 2 == 0) return n * n;
    return 0;
}
bool caculate(stack<int>& Integer, stack<int>& op) {
    char opr = op.top(); op.pop();
    int b = Integer.top(); Integer.pop();
    int a = Integer.top(); Integer.pop();
    if(opr == '+') Integer.push(a + b);
    else if(opr == '-') Integer.push(a - b);
    else if(opr == '*') Integer.push(a * b);
    else if(opr == '/') 
    {
        //错误
        if(b == 0) return false;
        Integer.push(a / b);
    }
    else if(opr == '^') Integer.push(FE(a, b));
    return true;
}
void getAns(string& s) {
    stack<int> Integer; stack<int> op;
    for(int i = 0; i < s.size(); i++) {
        //数字
        int n = 0;
        if(s[i] <= '9' && s[i] >= '0') {
            while(s[i] <= '9' && s[i] >= '0') {
                n *= 10;
                n += s[i] - '0';
                i++;
            }
            i--;
            Integer.push(n);
        }
        else if(s[i] == '(') op.push(s[i]);
        else if(s[i] == ')') {
            //弹栈直到碰到左括号
            while(op.top() != '(') {
                if(!caculate(Integer, op)) {cout << "INVALID" << '\n'; return;}
            }
            //弹栈左括号
            op.pop();
        }
        //运算符
        else {
            //栈外优先级小于等于栈顶，弹栈运算直到大于
            while(!op.empty() && op.top() != '(' && Out[s[i]] <= In[op.top()]) {
                if(!caculate(Integer, op)) {
                    cout << "INVALID" << '\n';
                    return;
                }
            }
            //当前运算符入栈
            op.push(s[i]);
        }
    }
    while(!op.empty()) {
        if(!caculate(Integer, op)) {
            cout << "INVALID" << '\n';
            return;
        }
    }
    cout << Integer.top() << '\n';
}
int main() {
    //初始化p数组，记住^的栈外优先级大于栈内
    In['+'] = 1; In['-'] = 1; In['*'] = 2; In['/'] = 2; In['^'] = 3;
    Out['+'] = 1; Out['-'] = 1; Out['*'] = 2; Out['/'] = 2; Out['^'] = 4;
    string s;
    while(cin >> s) {
        getAns(s);
    }
    return 0;
}