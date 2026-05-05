#include <bits/stdc++.h>
#define ll long long
#define leona ios_base::sync_with_stdio(false); cin.tie(NULL);          
 
using namespace std;
int priority(char c){
    if(c == 'u') return 3; // Unary minus
    if(c == '+' || c == '-') return 1;
    return 0;
}

string to_postfix(string exp){
    stack<char> s;
    string output = "";
    bool expectOp = true; 

    for(int i = 0; i < exp.size(); i++){
        if(exp[i] == ' ') continue;

        if(isdigit(exp[i])){
            while(i < exp.size() && isdigit(exp[i])){
                output += exp[i++];
            }
            output += '|'; // Delimiter for numbers
            i--;
            expectOp = false;
        }
        else if(exp[i] == '('){
            s.push('(');
            expectOp = true;
        }
        else if(exp[i] == ')'){
            while(!s.empty() && s.top() != '('){
                output += s.top();
                s.pop();
            }
            if(!s.empty()) s.pop();
            expectOp = false;
        }
        else {
            char op = exp[i];
            if(expectOp && op == '-') op = 'u'; // Mark as unary

            while(!s.empty() && s.top() != '(' && priority(s.top()) >= priority(op)){
                output += s.top();
                s.pop();
            }
            s.push(op);
            expectOp = true;
        }
    }
    while(!s.empty()){
        output += s.top();
        s.pop();
    }
    return output;
}

float evaluate_postfix(string postfix){
    stack<float> st;
    for(int i = 0; i < postfix.size(); i++){
        if(isdigit(postfix[i])){
            float num = 0;
            while(i < postfix.size() && isdigit(postfix[i])){
                num = num * 10 + (postfix[i++] - '0');
            }
            st.push(num);
        }
        else if(postfix[i] == 'u'){
            float val = st.top(); st.pop();
            st.push(-val);
        }
        else if(postfix[i] == '+' || postfix[i] == '-'){
            float op2 = st.top(); st.pop();
            float op1 = st.top(); st.pop();
            if(postfix[i] == '+') st.push(op1 + op2);
            else st.push(op1 - op2);
        }
    }
    return st.top();
}
int main(){
    string infix;
    cin >> infix;
    string postfix = to_postfix(infix);
    cout << "Postfix: " << postfix << endl;
    float result = evaluate_postfix(postfix);
    cout << "Result: " << result << endl;
}
