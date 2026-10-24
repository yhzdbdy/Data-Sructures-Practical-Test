#include<bits/stdc++.h>
using namespace std;
//有乘方,依旧要设置栈内站外优先级
int In[100]; int Out[100];

void caculate(stack<double>& interger, stack<char>& op) {
    char opr = op.top(); op.pop();
    double b = interger.top(); interger.pop();
    double a = interger.top(); interger.pop();
    if(opr == '+') interger.push(a + b);
    else if(opr == '-') interger.push(a - b);
    else if(opr == '*') interger.push(a * b);
    else if(opr == '/') interger.push(a / b);
    else if(opr == '^') interger.push(pow(a,b));
}
void getAns(string& s) {
    stack<char> op; stack<double> interger;
    for(int i = 0; i < s.size(); i++) {
        //处理数字
        if(s[i] <= '9' && s[i] >= '0') {
            //我们使用了j来判断
            int j = i;
            while(j < s.size() && ((s[j] <= '9' && s[j] >= '0') || s[j] == '.')) {
                j++;
            }
            double n = stod(s.substr(i, j - i));
            interger.push(n);
            //更新i
            i = j - 1;
        }
        else if(s[i] == '(') op.push(s[i]);
        else if(s[i] == ')') {
            //弹栈直到左括号
            while(op.top() != '(') {
                caculate(interger, op);
            }
            op.pop();
        }
        else {
            //出栈
            while(!op.empty() && op.top() != '(' && Out[s[i]] <= In[op.top()]) {
                caculate(interger, op);
            }
            op.push(s[i]);
        }
    }
    while(!op.empty()) {
        caculate(interger, op);
    }

    //打印
    printf("%.2f\n", interger.top());
}
int main() {
    string s;
    In['+'] = 1; In['-'] = 1; In['*'] = 2; In['/'] = 2; In['^'] = 3;
    Out['+'] = 1; Out['-'] = 1; Out['*'] = 2; Out['/'] = 2; Out['^'] = 4;
    while(cin >> s) {
        getAns(s);
    }
    return 0;
}