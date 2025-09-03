//Write a program that checks if an expression has balanced parentheses
// lets write the basic functionality of stacks first

#include <iostream>
#include <string>
using namespace std;

class Stack{
    int top;
    char arr[50];

    // create a constructor to call the stack
    public:
    Stack(){
        top=-1;
        // paranthesis wala will checck later
    }

    // create the basic functions isempty, isfull, push and pop

    
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == 49; }

    void push(char x){
        if(isFull()){
            cout<<"stack overflow";
        }
        else{
            arr[++top]=x;
            
        }
}

char pop(){
    if (isEmpty()){
        cout<<"stack underflow"<<endl;
        return '\0';
    }
    else{
        //return arr[top--]
        char popval;
        popval=arr[top];
        top--;
        return popval;
    }
}
};

//make a bool for matching pair
bool matchPair(char open, char close){
    return(open=='[' && close==']')||
          (open=='{' && close=='}')||
          (open=='(' && close==')');

}
// make a function to check the balance of paranthesis

bool isBalanced(string &expr){
    Stack s;
    for(int i=0; i<expr.length(); i++){
        char ch=expr[i];

        if(ch=='('|| ch=='{'|| ch=='['){
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) {
                return false; // no opening bracket
            }

            char topchar= s.pop();
            if(! matchPair(topchar, ch)){
                return false;
            }
        }
    }
 return s.isEmpty(); // must be empty if balanced

}
int main() {
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr);  // allows spaces

    if (isBalanced(expr)) {
        cout << "Balanced" << endl;
    } else {
        cout << "Not Balanced" << endl;
    }

    return 0;
}
