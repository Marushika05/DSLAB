//Develop a menu driven program demonstrating the following operations on a Stack using array:
#include <iostream>
using namespace std;
// creating a stack

class Stack {
    int arr[5];
    int top;
public:
    // creating a constructor
    Stack() {
        top = -1;
        for (int i = 0; i < 5; i++) {
            arr[i] = 0; // initialize stack with value 0
        }
    }
    // creating functions

    bool isEmpty() {
        if (top == -1) {
            return true;
        }
        else {
            return false;
        }
    }

    bool isFull() {
        if (top == 4) {
            return true;
        }
        else {
            return false;
        }
    }

    // iska return type hum void rkh skte hain and usme int value pass krte hn
    void push(int val) {
        if (isFull()) {
            cout << "stack overflow" << endl;
        }
        else {
            top++;
            arr[top] = val;
        }
    }

    // pop functionn ki return type would be int 
    // removing the topmost value and returning it
    int pop() {
        if (isEmpty()) {
            cout << "stack underflow" << endl;
            return 0;
        }
        else {
            int popval;
            popval = arr[top];
            arr[top] = 0;
            top--;
            return popval;
        }
    }

    int count() {
        return (top + 1);
    }

// top ke refernce mein chalta like which element from the top
    int peek(int pos) {
        if (pos < 1 || pos > count()) {
            cout << "invalid position" << endl;
            return 0;
        }
        int index = top - pos + 1;
        return arr[index];
    }

    //yh bbhi upr se treat krega
    void change(int pos, int newval) {
        if (pos < 1 || pos > count()) {
            cout << "invalid position" << endl;
            return;
        }
        int index = top - pos + 1;
        arr[index] = newval;
        cout << "the new value at your given pos is: " << newval << endl;
    }

    // higher value to lower value i.e index zero wala sbse neeche
    void display() {
        if (isEmpty()) {
            cout << "stack is empty" << endl;
            return;
        }
        cout << "Stack (top to bottom):" << endl;
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }
};


int main() {
    //  need to crreate a menu to access the functons according to the needs
    Stack s1;
    int option, position, value;

    do {
        cout << "\n enter the option number to invoke the following commands:" << endl;
        cout << " option 1: push()" << endl;
        cout << " option 2: pop()" << endl;
        cout << " option 3: display()" << endl;
        cout << " option 4: isEmpty()" << endl;
        cout << " option 5: isFull()" << endl;
        cout << " option 6: count()" << endl;
        cout << " option 7: change()" << endl;
        cout << " option 8: peek()" << endl;
        cout << " option 9: exit" << endl;

        // creating a switch case
        cin >> option;

        switch (option) {
        case 1:
            cout << " enter a value to push in the stack: " << endl;
            cin >> value;
            s1.push(value);
            break;

        case 2:
            cout << " popped value is: " << s1.pop() << endl;
            break;

        case 3:
            s1.display();
            break;

        case 4:
            if (s1.isEmpty()) {
                cout << " stack is empty" << endl;
            }
            else {
                cout << " not empty" << endl;
            }
            break;

        case 5:
            if (s1.isFull()) {
                cout << " stack is full" << endl;
            }
            else {
                cout << " not full" << endl;
            }
            break;

        case 6:
            cout << " the count is: " << s1.count() << endl;
            break;

        case 7:
            cout << "enter the position (from top) and the new value" << endl;
            cin >> position >> value;
            s1.change(position, value);
            break;

        case 8:
            cout << " enter a position (from top) to peek in the stack: " << endl;
            cin >> position;
            cout << " value at pos is: " << s1.peek(position) << endl;
            break;

        case 9:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "enter a valid option no." << endl;
        }

    } while (option != 9);

    return 0;
}
