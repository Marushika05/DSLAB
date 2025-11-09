// bubble sort
// make a function
#include <iostream>
using namespace std;
void bubblesort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // swap
                int temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout<<"the final array after bubbble sort is: "<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i];
    }

}

int main(){
    int arr[10]={3,6,2,8,9,1};
    // imp
     int n = sizeof(arr) / sizeof(arr[0]);
    bubblesort(arr, n);
    return 0;
}