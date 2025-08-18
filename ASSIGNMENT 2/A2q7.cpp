//Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an inversion if 
//these numbers are out of order, i.e., i < j but A[i]>A[j ]. Write a program to count the number of
// inversions in an array
#include<iostream>
using namespace std;
class inversion{
int i, j;
int count=0;
public:

void inv(int arr[], int n){
    
   for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){// to check the next element and running a loop inside a loop 
            if(arr[i]>arr[j]){
                count++;

            }

        }
     }
    cout<<count<<endl;
    return;
}

};
int main(){
    inversion i;
    int arr[]={10,9,8,7,6,5};
    int size=sizeof(arr)/sizeof(arr[0]);
    i.inv(arr,size);
    return 0;

}
