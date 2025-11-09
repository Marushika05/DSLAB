// quick sort

#include <iostream>
using namespace std;
/*
Quick Sort:
- Divide & Conquer algorithm
- Picks a pivot, partitions the array so that:
  left side < pivot < right side
- Recursively sorts left and right parts
- Average: O(n log n), Worst: O(n^2), Space: O(log n) due to recursion
*/

// lets create a partion func

int partition(int arr[], int low, int high)
{
    // sbse pehle set the pivot
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (true)
    {
        // move i forward until we find an element greater than pivot
        while (i <= high && arr[i] <= pivot)
        {
            i++;
        }
        // move j backwards until we find an element smaller than pivot
        while (j >= low && arr[j] > pivot)
        {
            j--;
        }
        // indices cross ya same hoge

        if (i >= j)
        {
            break;
        }
        swap(arr[i], arr[j]);
    }
    // jb loop se break hokr bahar niklenge tb jo pivot hain and uss wqt jo j wala hoga unko swap krna h;
    swap(arr[low], arr[j]);

    return j;
}
// abb quick sort ka function likhenge

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // partition wala pt dhundna h
        int pi = partition(arr, low, high);
        // Recursively sort left and right partitions
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    quickSort(arr, 0, n - 1);

    cout << "Sorted array:   ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}