//Write a program for the evaluation of a Postfix expression

#include <iostream>
#include <cmath>   
using namespace std;

class Stack {
    int arr[50];
    int top;

public:
    Stack() { top = -1; }

    void push(int val) {
        if (top == 49) {
            cout << "Stack Overflow\n";
        } else {
            top++;
            arr[top] = val;
        }
    }

    int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return 0;
        } else {
            int val = arr[top];
            top--;
            return val;
        }
    }

    bool isEmpty() {
        return (top == -1);
    }
};

int evaluatePostfix(string exp) {
    Stack st;

    for (int i = 0; i < exp.length(); i++) {
        char c = exp[i];

        // if it's a digit
        if (c >= '0' && c <= '9') {
            st.push(c - '0');   // convert char to int
        }
        else {
            int val2 = st.pop();
            int val1 = st.pop();

            switch (c) {
                case '+': st.push(val1 + val2); break;
                case '-': st.push(val1 - val2); break;
                case '*': st.push(val1 * val2); break;
                case '/': st.push(val1 / val2); break;
                case '^': st.push(pow(val1, val2)); break;
            }
        }
    }

    return st.pop();  // final result
}

int main() {
    string postfix;
    cout << "Enter postfix expression (single-digit operands): ";
    cin >> postfix;

    int result = evaluatePostfix(postfix);
    cout << "Result = " << result << endl;

    return 0;
}
