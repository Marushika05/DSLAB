//Bubble Sort is the simplest sorting algorithm that works by repeatedly swapping the adjacent
// elements if they are in wrong order. Code the Bubble sort with the following elements:
//64 34 25 12 22 11 90
// bubble sort algo compares two values and places them in ascending or dec order 
#include<iostream>
using namespace std;
   void bsort(int arr[], int n){
    int i,j;
    //ii for no of passes and j for swaping and agter each elements keep getting sorted so n-i-1
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main() {
    int arr[] = {64 ,34, 25, 12, 22, 11, 90};
    int ar[] = {12,25,87,76,2,55,14,67,88,76};
    
    int m = sizeof(ar) / sizeof(ar[0]);
    int n = sizeof(arr) / sizeof(arr[0]);
    
    bsort(arr, n);
    bsort(ar, m);

    cout << "Sorted array 1: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nSorted array 2: ";
    for (int i = 0; i < m; i++) {
        cout << ar[i] << " "; 
    }
    
    return 0;
}

    
