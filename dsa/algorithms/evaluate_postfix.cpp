#include <bits/stdc++.h>
using namespace std;

// algo to evaluate an arithmetic expression in Polish notation

int prec(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

string infixToPostfix(const string& s) {
    string out;
    stack<char> st;
    for (size_t i = 0; i < s.size(); ++i) {
        char c = s[i];
        
        if (c == ' ') {
            continue
        };

        if (isalpha(c) || isdigit(c)) {            
            out += c;
            out += ' ';
        } 

        else if (c == '(') {
            st.push(c);
        } 

        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                out += st.top(); out += ' '; st.pop();
            }
            if (!st.empty() && st.top() == '(') {
                st.pop();
            }
        } 

        else { // operator
            while (!st.empty() && prec(st.top()) >= prec(c)) {
                out += st.top(); out += ' '; st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        out += st.top(); out += ' '; st.pop();
    }

    if (!out.empty()) {
        out.pop_back()
    };

    return out;
}


double evaluatePostfix(const string& postfix,const unordered_map<char, double>& val) 
{
    stack<double> st;
    for (size_t i = 0; i < postfix.size(); ++i) {
        char c = postfix[i];
        if (c == ' ') continue;

        if (isalpha(c)) {            
            auto it = val.find(c);
            if (it == val.end()) throw runtime_error("Variabila lipseste din map");
            st.push(it->second);
        } 
        else if (isdigit(c)) {         
            st.push(c - '0');
        } 
        else {                          
            if (st.size() < 2) throw runtime_error("Postfix invalid");
            double b = st.top(); st.pop();
            double a = st.top(); st.pop();
            switch (c) {
                case '+': st.push(a + b); break;
                case '-': st.push(a - b); break;
                case '*': st.push(a * b); break;
                case '/': st.push(a / b); break;
                default: throw runtime_error("Operator necunoscut");
            }
        }
    }
    if (st.size() != 1) throw runtime_error("Postfix invalid (rest pe stiva)");
    return st.top();
}

void run_evaluate_postfix() {
    string infix = "A*B + C*D + E/F - G";

    string postfix = infixToPostfix(infix);

    unordered_map<char, double> val{
        {'A',5}, {'B',1}, {'C',3}, {'D',2}, {'E',9}, {'F',3}, {'G',6}
    };

    double result = evaluatePostfix(postfix, val);

    cout << "Infix:   " << infix << "\n"; // A*B + C*D + E/F - G
    cout << "Postfix: " << postfix << "\n"; // A B * C D * + E F / + + G -
    cout << "Value (T): " << result << "\n"; // 8
}
