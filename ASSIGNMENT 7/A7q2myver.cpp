// selection sort
/*1. 0-n-2 tk i ie cycle run hoga
2. swap krne hai not switch and fis=rst ko min assume  krke star krna*/
///3. this sort needs the index of the minimum to replace it


//THIS IS WRIONG CODE BECAUSE OF WRONG LOGIC

#include <iostream>
using namespace std;
void selectionSort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        int min=arr[i];
        for (int j = i; j <= n - 1; j++)
        {

            if (arr[j] < min)
            {
                // store the value of j in min
                arr[j]=min;
            }
            
        }
        // swap
            int temp = min;
            min = arr[i];
            arr[i]=temp;
    }
}
int main(){
    int myarr[]={4,1,7,10,3,14,8};
    int size= sizeof(myarr)/sizeof(myarr[0]);
    selectionSort(myarr,size);
    for(int i=0; i<size; i++){
        cout<<myarr[i]<<" ";
       
    }
     return 0;

}