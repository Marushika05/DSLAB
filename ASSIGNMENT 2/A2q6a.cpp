// sparese matrix transpose
#include <iostream>
using namespace std;
int main()
{
    int m, n;
    cout << "enter the dimensions of arr: ";
    cin >> m >> n;
    int arr[m][n];
    cout << "enter the elements: ";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    // count number of non zero
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                count++;
            }
        }
    }

    int sp[count + 1][3];
    sp[0][0] = m;
    sp[0][1] = n;
    sp[0][2] = count;

    int row = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                sp[row][0] = i;
                sp[row][1] = j;
                sp[row][2] = arr[i][j];
                row++;
            }
        }
    }
    for (int i = 0; i < count + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {

            cout << sp[i][j] << " ";
        }
        cout << endl;
    }

    // cretaing transpose;
    int spt[count+1][3];
    spt[0][0]=n;
    spt[0][1]=m;
    spt[0][2]=count;

int t_row=1;
 
    int t_row = 1;

for (int col = 0; col < n; col++)
{
    for (int i = 1; i <= count; i++)  // start from 1
    {
        if (sp[i][1] == col)
        {
            spt[t_row][0] = sp[i][1]; // new row = old column
            spt[t_row][1] = sp[i][0]; // new column = old row
            spt[t_row][2] = sp[i][2]; // value remains the same
            t_row++;
        }
    }
}
cout << "\nTransposed Sparse Matrix (Triplet Form):\n";
for (int i = 0; i <= count; i++)
{
    for (int j = 0; j < 3; j++)
        cout << spt[i][j] << " ";
    cout << endl;
}



    return 0;
}