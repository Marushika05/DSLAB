//Write a program to count the total number of distinct elements in an array of length n.
#include<iostream>
using namespace std;
class distinct{
int i, j;
int count=0;
public:

void dis(int arr[], int n){
    
  for (int i = 0; i < n; i++) {
            bool isDuplicate = false;

            // check if arr[i] has appeared before
            for (int j = 0; j < i; j++) {
                if (arr[i] == arr[j]) {
                    isDuplicate = true;
                    break; // no need to check further
                }
            }

            if (!isDuplicate) {
                count++; // new distinct element found
            }
        }
    cout<<count<<endl;
    

    return;
}

};
int main(){
    distinct d;
    int arr[]={10,10,9,9,9,8,7,6,5};
    int size=sizeof(arr)/sizeof(arr[0]);
   d.dis(arr,size);
    return 0;
}