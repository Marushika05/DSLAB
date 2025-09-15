// Develop a menu driven program demonstrating the following operations on simple
// Queues: enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek()
/*queue implements fifo algo and has similarities to stack*/
#include <iostream>
using namespace std;
class Queue
{
    // we need to define
    int *arr;
    int front;
    int rear;
    int size;
    // we need a constructor to initialize the values
public:
    Queue()
    {
        size = 10001;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    bool isEmpty()
    {
        return front == rear;
    }

    bool isFull()
    {
        return rear == size;
    }

    // similar to push function
    void enqueue(int x)
    {
        if (isFull())
        {
            cout << "queue already full" << endl;
        }
        else
        {
            arr[rear] = x;
            rear++;
            // the above is imp(mistake sometimes)
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "queue is empty" << endl;
        }

        else
        {
            // we are not storing the value of dequeued element anywhere, we're just dequeing it
            // cout << "dequeued element" << arr[front] << endl;
            // front++;
int ans=arr[front];
            arr[front]=-1;
            front++;
            if(front==rear){
                front=0;
                rear=0;
            }
            return ans;
        }

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
        }
        else
        {
            cout << "your elements in the queue are: " << endl;
            for(int i=front; i<rear; i++){
                cout<<arr[i]<<"";

            }
            cout<<endl;
        }
    }
};
//creating a menu
int main() {
    Queue q;
    int option, val;

    do {
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

        switch (option) {
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

