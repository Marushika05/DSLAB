//Design the Logic to Find a Missing Number in a Sorted Array.
#include <iostream>
using namespace std;

void missing(int arr[], int n,int gap){
int i;
// if we use n then i+1 woould be n+1
for(i=0; i<n-1;i++){
    int diff=arr[i+1]-arr[i];
if(diff !=gap){
    cout<<"the missing number is "<<arr[i]+gap;
    cout<<endl;
    
    
}
}
return;

} 

int main(){
   int arr[]={1,2,3,4,6,8,10,12};
   int n=sizeof(arr)/sizeof(arr[0]);
   missing(arr,n,1);
   return 0;
}