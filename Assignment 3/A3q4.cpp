#include <iostream>
using namespace std;

class Stack {
    char arr[50];
    int top;
public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == 49; }

    void push(char c) {
        if (!isFull()) {arr[++top] = c;}
    }

    char pop() {
        if (!isEmpty()){ return arr[top--]};
        return 0;
    }

    char peek() {
        if (!isEmpty()) return arr[top];
        return 0;
    }
};

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool isOperand(char c) {
    return ( (c >= 'A' && c <= 'Z') ||
             (c >= 'a' && c <= 'z') ||
             (c >= '0' && c <= '9') );
}

string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (isOperand(c)) {
            postfix += c;
        }
        else if (c == '(') {
            s.push(c);
        }
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop(); // remove '('
        }
        else if (isOperator(c)) {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(c)) {
                postfix += s.pop();
            }
            s.push(c);
        }
    }

    while (!s.isEmpty()) {
        postfix += s.pop();
    }

    return postfix;
}

int main() {
    int option;
    string infix;

    do {
        cout << "\nMenu:\n";
        cout << "1. Convert Infix to Postfix\n";
        cout << "2. Exit\n";
        cout << "Enter option: ";
        cin >> option;

        switch (option) {
        case 1:
            cout << "Enter infix expression (no spaces): ";
            cin >> infix;
            cout << "Postfix expression: " << infixToPostfix(infix) << endl;
            break;
        case 2:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid option!\n";
        }
    } while (option != 2);

    return 0;
}
   
