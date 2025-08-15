#include <iostream>
using namespace std;

// Binary search function
void binary(int arr[], int n, int num) {
    int start=0;
    int end=n-1;
    int mid=(start+end)/2 ;
    while (start <= end) {
        mid = (start + end) / 2;

        if (arr[mid] == num) {
            cout << "Found at index: " << mid << endl;
            return;
        } 
        else if (arr[mid] < num) {
            start = mid + 1;
        } 
        else {
            end = mid - 1;
        }
    }
    cout << "Not found" << endl;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int size = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    int num;

    cout << "Enter number to search: ";
    cin >> num;

    binary(arr, size, num); // Pass array, size, and number to search

    return 0;
}
