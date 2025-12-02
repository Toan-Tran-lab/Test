#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool ValidBrace(string s) {
    stack<char> S;
    for (int i=0; i<s.length(); ++i) {
        if (s[i]=='(' || s[i]=='[' || s[i]=='{') {
            S.push(s[i]);
        }
        else if (!S.empty() && ((s[i]==')' && S.top()=='(') || (s[i]==']' && S.top()=='[') || (s[i]=='}' && S.top()=='{'))) {
            S.pop();
        }
        else 
            return false;
    }
    return S.empty() ? 1 : 0;
}

int main () {
    string s = "{";
    cout << ValidBrace(s);
}