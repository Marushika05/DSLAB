#include <iostream>
using namespace std;
// Implement the logic to
// a. Reverse the elements of an array
// b. Find the matrix multiplication
// c. Find the Transpose of a Matrix

class logic{

    int i,j,n;
    int arr[100];
    public:
    void create(){
    cout<<"enter the number of elements : "<<endl;
    cin>>n;
    cout<<"enter the elements"<<endl;
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"the final array is"<<endl;
    for(i=0;i<n;i++){
        cout<<arr[i]<<"\t";
        cout<<endl;
        
    }
    return;
    }
   void reverse(){
        for(i=0;i<n/2;i++){
            int temp=arr[i];
            arr[i]=arr[n-i-1];// inwads move and swap
            arr[n-i-1]= temp;

        }
         cout << "Array after reversing: " << endl;
    for (i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
    return;
   }
};

int main() {
    logic l;
   l.create();
    l.reverse();
    return 0;
}