/*Develop a menu driven program demonstrating the following operations on Circular Queues:
enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().
*/
#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int front, rear, size;

    // initialization using constructor
public:
   Queue() {

    size = 5;          // set size first
    arr = new int[size];
    front = rear = -1;
}

    bool isEmpty()
    {
        // pehla element ayega abhi tbhi f==-1
        return front == -1;
    }

    bool isFull()
    {
       return (front == (rear + 1) % size);
    }

    
  void enqueue(int data)
{
    if (isFull())
    {
        cout << "Queue is full!" << endl;
        return; // stop here, don’t overwrite
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % size;
    }

    arr[rear] = data;
}


    int dequeue()
    {
        if (isEmpty())
        {
            cout << "queue is empty" << endl;
            return -1;
        }
        int x = arr[front];
        cout << "Dequeued element: " << x << endl;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }

        return x;
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
        }
        else
        {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};

// creating a menu
int main()
{
    Queue q;
    int option, val;

    do
    {
        cout << "\nChoose an operation:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. isEmpty\n";
        cout << "4. isFull\n";
        cout << "5. Display\n";
        cout << "6. Peek\n";
        cout << "7. Exit\n";
        cout << "Enter option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> val;
            q.enqueue(val);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            cout << (q.isEmpty() ? "Queue is empty\n" : "Queue is not empty\n");
            break;

        case 4:
            cout << (q.isFull() ? "Queue is full\n" : "Queue is not full\n");
            break;

        case 5:
            q.display();
            break;

        case 6:
            q.peek();
            break;

        case 7:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid option! Try again.\n";
        }
    } while (option != 7);

    return 0;
}
// slot 0 will be reused after dequeue but logical display mein we wont see that
//it si working in circularr manner
