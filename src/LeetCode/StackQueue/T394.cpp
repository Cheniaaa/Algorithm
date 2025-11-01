#include "iostream"
#include "stack"

using namespace std;


string decodeString(string s) {
    if (s == "") {
        return "";
    }
    int num = 0, time = 0;
    string res = "";
    stack<string> str_stack;
    stack<int> num_stack;
    for (const auto &item: s) {
        if (item >= '0' && item <= '9') {
            num = num * 10 + item - '0';
        } else if (item >= 'a' && item <= 'z' || item >= 'A' && item <= 'Z') {
            res = res + item;
        } else if (item == '[') {//将数字和字符串入栈
            num_stack.push(num);
            num = 0;
            str_stack.push(res);
            res = "";
        } else {//item为']'
            time = num_stack.top();
            num_stack.pop();
            for (int i = 0; i < time; ++i) {
                str_stack.top() += res;
            }
            res = str_stack.top();
            str_stack.pop();
        }

    }
    return res;
}


int main() {
    string s = "abc3[cd]xyz";
    cout << decodeString(s);
}