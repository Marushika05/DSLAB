//Write a program to find sum of every row and every column in a two-dimensional array.
#include <iostream>
using namespace std;

class matrix{
int i,j,n,r,c;
int mat1[100][100];

public:
    void create() {
        cout << "Enter rows: ";
        cin >> r;
        cout << "Enter cols: ";
        cin >> c;

        cout << "Enter matrix elements:" << endl;
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                cin >> mat1[i][j];
            }
        }

        cout << "Final matrix is:" << endl;
        for (i = 0; i < r; i++) {
            
            for (j = 0; j < c; j++) {
                cout << mat1[i][j] << "\t"; 
            }
            cout << endl; 
        }
        return;
        }

        void sum(){
           //rows
          for (int i = 0; i < r; i++) {
            int rowSum = 0;
            for (int j = 0; j < c; j++) {
                rowSum += mat1[i][j];
            }
            cout << "Row " << i + 1 << ": " << rowSum << endl;
        } cout << "\nSum of each column:\n";
        for (int j = 0; j < c; j++) {
            int colSum = 0;
            for (int i = 0; i < r; i++) {
                colSum += mat1[i][j];
            }
            cout << "Col " << j + 1 << ": " << colSum << endl;
        }
    }
};

int main(){
    matrix m1,m2;
    m1.create();
    //m2.create();
    m1.sum();
}