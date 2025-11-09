// insertion sort
/*for n elements n-1 times loops run hoga and eint his algorithm we have shifting and NOT swapping */

#include <iostream>
using namespace std;

void insertionSort(int n, int arr[])
{
    // sbse pehle jo element chaeck krna usko teemp mein store krwalena
    for (int i = 1; i < n; i++)
    { // we start from second index assuming first one to be sorted so i=1:n
        int temp = arr[i];
        // j should strat from one index before i;
        int j = i - 1;
        for (; j >= 0; j--)
        { 
            if (arr[j] > temp)
            {
                // shift
                arr[j + 1] = arr[j];
            }
            else
            { // ruk jao
                break;
            }
        } 
        
        // yh neeche wala out of socpe hojayega isiliye hum j ko for ke bahar likdenge
        /*this line is very important kyunki agar humne saare elements right mein shift krdiye toh j=-1
        otherwise basically jaunse elemnt ko hum lekr chal rhe hain uski location detrmine krrh e hum after
        storing another elemnt uski jgh pr*/
        arr[j + 1] = temp;
    }
    return;
}

int main()
{
    int myarr[] = {39, 77, 11, 33, 8, 9, 98};
    int size = sizeof(myarr) / sizeof(myarr[0]);
    insertionSort(size, myarr);
    for (int i = 0; i < size; i++)
    {
        cout << myarr[i] << " " << endl;
    }
    return 0;
}
/*
{310, 8, 1, 3, 4, 5}
i=1 -> temp=8, j=0 (310>8 so shift), array = {310,310,1,3,4,5}, j=-1, place 8 → {8,310,1,3,4,5}
        i=2 -> temp=1, j=1 (310>1 shift), {8,310,310,3,4,5}, j=0 (8>1 shift), {8,8,310,3,4,5}, j=-1, place 1 → {1,8,310,3,4,5}
        i=3 -> temp=3, j=2 (310>3 shift), {1,8,310,310,4,5}, j=1 (8>3 shift), {1,8,8,310,4,5}, j=0 (1>3? no) break, place 3 → {1,3,8,310,4,5}
        i=4 -> temp=4, j=3 (310>4 shift), {1,3,8,310,310,5}, j=2 (8>4 shift), {1,3,8,8,310,5}, j=1 (3>4? no) break, place 4 → {1,3,4,8,310,5}
        i=5 -> temp=5, j=4 (310>5 shift), {1,3,4,8,310,310}, j=3 (8>5 shift), {1,3,4,8,8,310}, j=2 (4>5? no) break, place 5 → {1,3,4,5,8,310}
        Final sorted array = {1,3,4,5,8,310}*/
        
//WHILE LOOP VERSION 
        /*for (int i = 1; i < n; i++) // start from 1
    {
        int temp = arr[i];
        int j = i - 1;

        // shift elements greater than temp to the right
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // place temp at its correct position
        arr[j + 1] = temp;
    }*/