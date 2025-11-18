#include <iostream>
using namespace std;

struct Heap
{
    int arr[100];
    int size;
};

// Function to heapify a subtree (Max Heap)
void maxHeapify(Heap &h, int i)
{ // indexing 1 se start kri hai
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= h.size && h.arr[left] > h.arr[largest])
        largest = left;
    if (right <= h.size && h.arr[right] > h.arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(h.arr[i], h.arr[largest]);
        maxHeapify(h, largest);
    }
}

// Function to heapify subtree (Min Heap)
void minHeapify(Heap &h, int i)
{
    int smallest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= h.size && h.arr[left] < h.arr[smallest])
        smallest = left;
    if (right <= h.size && h.arr[right] < h.arr[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(h.arr[i], h.arr[smallest]);
        minHeapify(h, smallest);
    }
}

// Heap sort to get *increasing* order (Max Heap)
void heapSortIncreasing(Heap &h)
{
    // Build Max Heap
    // hum leafs dekh rhe hain, that wwould be n/2 jaahan n is the total number of elms
    for (int i = h.size / 2; i >= 1; i--)
        maxHeapify(h, i);

    // Extract elements one by one
    for (int i = h.size; i >= 2; i--)
    {
        swap(h.arr[1], h.arr[i]);
        h.size--;
        maxHeapify(h, 1);
    }
}

// Heap sort to get *decreasing* order (Min Heap)
void heapSortDecreasing(Heap &h)
{
    // Build Min Heap
    for (int i = h.size / 2; i >= 1; i--)
        minHeapify(h, i);

    for (int i = h.size; i >= 2; i--)
    {
        swap(h.arr[1], h.arr[i]);
        h.size--;
        minHeapify(h, 1);
    }
}

// Display array
void display(Heap h)
{
    for (int i = 1; i <= h.size; i++)
        cout << h.arr[i] << " ";
    cout << endl;
}

int main()
{
    Heap h;
    cout << "Enter number of elements: ";
    cin >> h.size;

    cout << "Enter elements: ";
    for (int i = 1; i <= h.size; i++)
        cin >> h.arr[i];

    int choice;
    cout << "\n1. Sort in Increasing Order\n2. Sort in Decreasing Order\nEnter choice: ";
    cin >> choice;

    if (choice == 1)
    {
        Heap temp = h; // copy heap
        heapSortIncreasing(temp);
        cout << "Sorted (Increasing): ";
        display(temp);
    }
    else if (choice == 2)
    {
        Heap temp = h;
        heapSortDecreasing(temp);
        cout << "Sorted (Decreasing): ";
        display(temp);
    }
    else
    {
        cout << "Invalid";
    }

    return 0;
}
